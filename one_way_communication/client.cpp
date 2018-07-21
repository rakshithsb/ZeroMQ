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

	for(i=0;i!=10;i++)
	{
		msg.arr[i]=i;	
	}
	
	for(i=0;i!=1;i++)
	{
		zmq_send(requester,&msg, sizeof(Message),0);
	}
	
	zmq_close (requester);
	zmq_ctx_destroy (context);
	return 0;
}
