struct sockaddr 
{
       unsigned char sa_len;                     /* total length */
       sa_family_t   sa_family;                  /* address family */
       char          sa_data[14];                /* actually longer; address value */
};


struct sockaddr_in 
{
       uint8_t              sin_len;
       sa_family_t          sin_family;
       in_port_t            sin_port;
       struct	in_addr       sin_addr;
       char                 sin_zero[8];
};

#define       SOCK_MAXADDRLEN      255           /* longest possible addresses */
#define       AF_UNSPEC     0              /* unspecified */
#define       AF_LOCAL      1             /* local to host (pipes, portals) */
#define       AF_UNIX       AF_LOCAL      /* backward compatibility */
#define       AF_INET       2             /* internetwork: UDP, TCP, etc. */
#define       AF_IMPLINK    3             /* arpanet imp addresses */
#define       AF_PUP        4             /* pup protocols: e.g. BSP */
#define       AF_CHAOS      5             /* mit CHAOS protocols */
#define       AF_NS         6             /* XEROX NS protocols */
#define       AF_ISO        7             /* ISO protocols */
#define       AF_OSI        7
#define       AF_ECMA       8             /* European computer manufacturers */
#define       AF_DATAKIT    9             /* datakit protocols */
#define       AF_CCITT      10            /* CCITT protocols, X.25 etc */
#define       AF_SNA	       11            /* IBM SNA */
#define       AF_DECnet     12            /* DECnet */
#define       AF_DLI	       13            /* DEC Direct data link interface */
#define       AF_LAT	       14            /* LAT */
#define       AF_HYLINK     15            /* NSC Hyperchannel */
#define       AF_APPLETALK  16            /* Apple Talk */
#define       AF_ROUTE      17            /* Internal Routing Protocol */
#define       AF_LINK       18            /* Link layer interface */
#define       AF_COIP       20            /* connection-oriented IP, aka ST II */
#define       AF_CNT        21            /* Computer Network Technology */
#define       AF_IPX        23            /* Novell Internet Protocol */
#define       AF_SIP        24            /* Simple Internet Protocol */
#define       AF_ISDN       26            /* Integrated Services Digital Network*/
#define       AF_E164       AF_ISDN       /* CCITT E.164 recommendation */
#define       AF_INET6      28            /* IPv6 */
#define       AF_NATM       29            /* native ATM access */
#define       AF_ATM        30            /* ATM */
#define       AF_NETGRAPH   32            /* Netgraph sockets */
#define       AF_SLOW       33            /* 802.3ad slow protocol */
#define       AF_SCLUSTER   34            /* Sitara cluster protocol */
#define       AF_ARP        35      
#define       AF_BLUETOOTH  36            /* Bluetooth sockets */
#define       AF_MAX        37          
