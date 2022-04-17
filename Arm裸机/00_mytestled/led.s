.global _start

_start:
/*使能外设时钟 */
    ldr r1, =0xffffffff

    ldr r0, =0x020c4068
    str r1, [r0]

    ldr r0, =0x020c406c
    str r1, [r0]

    ldr r0, =0x020c4070
    str r1, [r0]

    ldr r0, =0x020c4074
    str r1, [r0]

    ldr r0, =0x020c4078
    str r1, [r0]

    ldr r0, =0x020c407c
    str r1, [r0]

    ldr r0, =0x020c4080
    str r1, [r0]

    /*GPIO1_IO3复用GPIO */
    ldr r0, =0x020e0068
    ldr r1, =0x5
    str r1, [r0]

    /*配置电气属性 
     * bit0: 0 低速率
     * bit5-3: 110 R0/6驱动能力
     * bit7-6: 10  100MHz速度
     * bit11:  0   关闭开漏输出
     * bit12:  1   使能pull/keeper
     * bit13:  0   keeper
     * bit15-14: 00 100k下拉
     * bit16:  0   关闭hys
     */

    ldr r0, =0x020e02f4
    ldr r1, =0x10b0
    str r1, [r0]

    /*设置GPIO为输出，GPIO1_GDIR的bit3为1 */
    ldr r0, =0x0209c004
    ldr r1, =0x0000008
    str r1, [r0]

    /*打开LED， 设置GPIO1_IO03 为0， 设置GPIO1_DR*/
    ldr r0, =0x0209c000
    ldr r1, =0
    str r1, [r0]

loop:
    b loop



