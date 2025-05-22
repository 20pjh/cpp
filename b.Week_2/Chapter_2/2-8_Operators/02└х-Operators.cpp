#include <stdio.h>
int main()
{
	char ch;
	int i, j, max;

	printf("���ĺ��� �Է��ϼ���: ");
	scanf("%c", &ch);
	printf(" �Է¹���: %c(10���� %d)\n", ch, ch);
	printf(" ��������: %c(10���� %d)\n", ch + 1, ch + 1);
	printf(" �����ּ�: 0x%x\n\n", &ch);

	printf("�� ������ �Է��ϼ���: ");
	scanf("%d%d", &i, &j);
	printf(" %d / %d    \t= %d\n", i, j, i / j);
	printf(" %d %% %d   \t= %d\n", i, j, i%j);
	printf(" %d/(double)%d \t= %lf\n", i, j, i / (double)j);
	printf(" %d�� %d�� ū�� \t= %d\n", i, j, (i>j) ? i : j);
	printf(" %d | %d     \t= %d\n", i, j, i | j);
	printf(" %d & %d     \t= %d\n", i, j, i&j);
	printf(" %d ^ %d     \t= %d\n", i, j, i^j);
	printf(" %d >> 2     \t= %d\n", i, i >> 2);
	printf(" %d << 2     \t= %d\n", i, i << 2);
}