#include <stdio.h>
#include <string.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <sys/ioctl.h>
#include <linux/if.h>
#include <linux/if_packet.h>
#include <linux/if_ether.h>
#include <linux/in.h>
#include <linux/sockios.h>

int socket_fd = -1;
struct ifreq interface;
struct sockaddr_ll socket_link;

void main()
{
	int i = 0;
	int len = 0;
	unsigned char buf[1024];

	socket_fd = socket(PF_PACKET, SOCK_RAW, IPPROTO_RAW);
	if(0 > socket_fd)
	{
		printf("%s-%d:Failed to create socket.\n", __func__, __LINE__);
		return ;
	}

	memset(&interface, 0, sizeof(struct ifreq));
	strcpy(interface.ifr_name, "eth0");

	/* »ñµÃÍø¿¨ÐòºÅ */
	if(ioctl(socket_fd, SIOCGIFINDEX, &interface))
	{
		printf("%s-%d:Failed to get interface info.\n", __func__, __LINE__);	
		return ;
	}
	printf("%s-%d:SIOCGIFINDEX %d\n", __func__, __LINE__, interface.ifr_ifindex);

	memset(&socket_link, 0, sizeof(struct sockaddr_ll));
	socket_link.sll_ifindex = interface.ifr_ifindex;
	socket_link.sll_family = AF_PACKET;
	socket_link.sll_protocol = htons(ETH_P_ALL);
	if(bind(socket_fd, (struct sockaddr *)&socket_link, sizeof(struct sockaddr_ll)))
	{
		printf("%s-%d:Failed to bind socket.\n", __func__, __LINE__);
		return ;
	}

	while(1)
	{
		printf("start\n");
		len = recvfrom(socket_fd, buf, 1024, 0, NULL, NULL);

		if(0 < len)
		{
			for(i = 0; i < len; i++)
			{
				printf("%02X ", buf[i]);
				if((i+1)%16 == 0)
					printf("\n");
			}	
		}
		printf("\nend\n");
	}
}
