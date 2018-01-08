#include "ipv4.h"
void
main()
{
    // in_addr > 4 > unsigned int
    // u_char > unsigned char > 最高位不推导 > 1 > 8
    // ---- ----
    // 1100 0000
    // 1x2^6 + 1x2^7
    // c0: c = 12, 0 = 0 >
    // u_char * => p[0]
    //
    struct in_addr ret;
    inet_aton("192.168.1.1", &ret);
    int addr = 192168;
    int *pA  = &addr;
    printf("addr> %x\n pA> %x val: %c\n", &addr, &pA[0], pA[0]);
    const u_char *p = (const u_char *) &ret;
    printf("s_addr> %x\n", &ret.s_addr);
    printf("0>%x 1>%x 2>%x 3>%x\n", &p[0], &p[1], &p[2], &p[3]);
    printf("%u\n", p[0]);
//    printf("%d\n", ret.s_addr);
//    printf("%x:%x\n", &ret, &(ret.s_addr));
    printf("%x:%u:%u\n", (unsigned int) ret.s_addr, ntohl(ret.s_addr));
}