#include<stdio.h>
#include<stdint.h>
#include<stddef.h>
#include<netinet/in.h>

int main()
{
	FILE *in1 = fopen("thousand.bin","rb");
	FILE *in2 = fopen("five-hundred.bin","rb");
	uint32_t num1[32], num2[32];
	uint32_t* p1, *p2;
	uint32_t n1, n2;
	int a,b,sum;
	fread(num1, sizeof(uint32_t*), 1, in1);
	fread(num2, sizeof(uint32_t*), 1, in2);
	p1 = reinterpret_cast<uint32_t*>(num1);
	p2 = reinterpret_cast<uint32_t*>(num2);
	n1  = ntohl(*p1);
	n2 = ntohl(*p2);
	sum = int(n1) + int(n2);
	printf("%d(0x%x) + %d(0x%x) = %d(0x%x)\n", n1,n1,n2,n2,sum,sum);

	fclose(in1);
	fclose(in2);
	return 0;
}
