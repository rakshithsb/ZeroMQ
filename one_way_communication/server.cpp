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
	try
	{
		zmq::context_t context (1);
		zmq::socket_t socket (context, ZMQ_DEALER);
		socket.bind ("tcp://*:5555");
	
		int val;
		int i;
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
			for(int i=0;i<10;i++)
			{
				msg.sum[i]=100+msg1->arr[i];	
				std::cout<<msg.sum[i]<<std::endl;
			}
		}
	}

	catch(const std::exception& e) 
	{
		std::cout << "Caught exception \"" << e.what() << "\"\n";
	}
return 0;
}


