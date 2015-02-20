#include <stdio.h>


void revert(int left, int right, int *mas) {
	
	while (left < right)
	{
		int temp = mas[left];
		mas[left] = mas[right];
		mas[right] = temp;
		left++;
		right--;
	}
}

int main() {

	const int first = 0;
	const int maxSize = 1000;
	int mas[maxSize];
	
	int mSize = 0;
	int nSize = 0;
	printf("Enter sizes of parts M and N: \n");
	scanf("%d %d", &mSize, &nSize);

	int last = mSize + nSize - 1;
	printf("Enter elements of parts: \n");
	for (int i = 0; i <= last; ++i)
		scanf("%d", mas + i);

	revert(first, mSize - 1, mas);
	revert(mSize, last, mas);
	revert(first, last, mas);

	printf("The revert of parts is :\n");
	for (int i = 0; i <= last; ++i)
		printf("%d ", mas[i]);
	printf("\n");

	return 0;
}