
#ifndef UTILS_H_
#define UTILS_H_
/* macro like function for set bit and clear bit */
#define  SET_BIT(REG,bit)           REG = (REG|(1<<bit))
#define  CLR_BIT(REG,bit)           REG= (REG &~ (1<<bit))
#define   GET_BIT(REG,bit)          ((REG >> bit) & 1 )




#endif /* UTILS_H_ */
