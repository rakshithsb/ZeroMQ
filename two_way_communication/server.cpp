#include <sstream>
#include <stdint.h>
#include <stdio.h>
#include "structure.h"
#include "zmq.hpp"
#include <sys/socket.h>
#include <string>
#include <iostream>
#include <unistd.h>
using namespace std;
int main () 
{
	int i;
	try
	{
		zmq::context_t context (1);
		zmq::socket_t socket (context, ZMQ_DEALER);
		socket.bind ("tcp://*:5555");

		void *context2 = zmq_ctx_new ();
		void *requester2 = zmq_socket (context2, ZMQ_DEALER); 
		zmq_connect (requester2, "tcp://localhost:5556");
	
		while(true)
		{
			Message* msg1;
			zmq::message_t zmsg;
			socket.recv(&zmsg);
			msg1 = (Message*)zmsg.data();

			printf("Received Array\n");
			for(i=0;i<10;i++)
			{
				std::cout<<msg1->arr[i]<<std::endl;	
				msg.sum[i]=1;
			}
		
			printf("Sum Array\n");
			for(i=0;i<10;i++)
			{
				msg.sum[i]=100+msg1->arr[i];	
				std::cout<<msg.sum[i]<<std::endl;
			}
			zmq_send(requester2,&msg, sizeof(Message),0);
		}
	}

	catch(const std::exception& e) 
	{
		std::cout << "Caught exception \"" << e.what() << "\"\n";
	}
	return 0;
}
