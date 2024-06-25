#ifndef STDTYPES_H_
#define STDTYPES_H_

typedef unsigned char	u8;
typedef signed char	s8;

typedef unsigned short	u16;
typedef signed short	s16;

typedef unsigned long	u32;
typedef signed long	s32;

typedef unsigned long long	u64;
typedef signed long long	s64;

typedef enum{
	FALSE,
	TRUE
	}boolean;
	
typedef enum{
	OK,
	NOK,
	OUTOFRANGE,
	NULL_PTR
	}Error_t;
	
#define NULLPTR	((void*)0)
#define NULL	0
#define MAX_U8	((u8)255)
#define MIN_U8	((u8)0)
#define MAX_S8	((s8)127)
#define MIN_S8	((s8)-128)
#define ZERO_S8	((s8)0)
	

#endif /* STDTYPES_H_ */
