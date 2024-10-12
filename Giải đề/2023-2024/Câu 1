/* Ý TƯỞNG:
- Gặp vị trí i nào trong mảng là SNT thì tiến hành kiểm tra các số ở vị trí thứ i+p (p là số tự nhiên lớn hơn i) xem có phải là số nguyên tố không. Nếu phải, cộng số đó vào giá trị của vị trí i, xóa số ở vị trí đó.
- Nếu không, tiến hành tăng biến count (biến đếm số lượng chuỗi con).*/



int checkPrimeNumber(int n) // Hàm kiểm tra số nguyên tố 
{
	int dem = 0;
	for (int i = 1; i <= n; i++)
	{
		if (n % i == 0)
		{
			dem++;
		}
	}
	if (dem == 2)
	{
		return 1;
	}
	return 0;
}



void delVal(int A[], int& N, int pos) // Hàm xóa phần tử tại vị trí pos 
{
	for (int i = pos; i < N - 1; i++)
	{
		A[i] = A[i + 1];
	}
	N--;
}

int reduceArray(int A[], int& N)
{
	int count = 0;
	for (int i = 0; i < N - 1; i++)
	{
		if (checkPrimeNumber(A[i]))
		{
			for (int j = i + 1; j < N; j++) // Tạo vòng lặp thứ hai để kiểm tra các số phía sau vị trí i 
			{
				if (checkPrimeNumber(A[j]))
				{
					A[i] += A[j];
					delVal(A, N, j);
					j--;
				}
				else
				{
					count++;
					break;
				}
			}
		}
	}
	return count;
}
