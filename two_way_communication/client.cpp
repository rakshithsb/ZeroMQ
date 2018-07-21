#include <sstream>
#include <zmq.hpp>
#include <string.h>
#include <stdio.h>
#include <unistd.h>
#include <sys/socket.h>
#include <iostream>
#include "structure.h"
using namespace std;
int main (void)
{
	int i;
	printf ("Sending to server…\n");
	void *context = zmq_ctx_new ();
	void *requester = zmq_socket (context, ZMQ_DEALER);
	zmq_connect (requester, "tcp://localhost:5555");
	
	zmq::context_t context1 (1);
	zmq::socket_t socket1 (context1, ZMQ_DEALER);
	socket1.bind ("tcp://*:5556");

	for(i=0;i!=10;i++)
	{
		msg.arr[i]=i;	
	}
	
	for(i=0;i!=10;i++)
	{
		zmq_send(requester,&msg, sizeof(Message),0);
	}
	
	for(i=0;i<10;i++)
	{
		Message* msg1;
		zmq::message_t zmsg;
		socket1.recv(&zmsg);
		msg1=(Message*)zmsg.data();
		std::cout<<msg1->sum[i]<<std::endl;	
	}

	zmq_close (requester);
	zmq_ctx_destroy (context);
	return 0;
}
