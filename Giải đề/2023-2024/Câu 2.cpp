// Câu a

/* Ý TƯỞNG:
- Tìm trong mảng SNT lớn nhất.
- Sau đó cho một vòng lặp biến chạy từ SNT lớn nhất đó trở dần về 2, kiểm tra số nào là SNT và kiểm trong mảng xem có số đó không. Nếu có, đó là SNT lớn nhì.*/

bool checkPrimeNumber(int n) // Hàm kiểm tra số nguyên tố 
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
		return true;
	}
	return false;
}


void findSpecialPoints(int mat[][MAXCOL], int nRow, int nCol, int& xA, int& yA, int& xB, int& yB)
{
	int max = INT_MIN;
	for (int i = 0; i < nRow; i++)
	{
		for (int j = 0; j < nCol; j++)
		{
			if (checkPrimeNumber(mat[i][j]) == true && mat[i][j] > max)
			{
				max = mat[i][j];
				xA = i;
				yA = j;
			}
		}
	}
	int tmp = 0;
	for (int x = max - 1; x >= 2; x--)
	{
		if (checkPrimeNumber(x) == true)
		{
			for (int i = 0; i < nRow; i++)
			{
				for (int j = 0; j < nCol; j++)
				{
					if (x == mat[i][j])
					{
						xB = i;
						yB = j;
						tmp = 1;
						break;
					}
				}
			}
		}
		if (tmp == 1)
		{
			break;
		}
	}
	cout << "Vi tri SNT lon nhat: (" << xA << ";" << yA << ")" << endl;
	cout << "Vi tri SNT lon nhi: (" << xB << ";" << yB << ")" << endl;
}









// Câu b

/* Ý TƯỞNG:
- Tạo mảng một chiều chứa các phần tử của mảng hai chiều theo chiều xoắn ốc như đề.
- Sau đó tạo các biến tìm vị trí của (xA,yA) và (xB,yB) trong mảng một chiều, nếu vị trí của số A > số B thì bắt đầu dò từ vị trí tiếp theo của số B và ngược lại.
- Cách này điều kiện của mảng phải là: Không có phần tử nào trùng nhau! Nếu trùng nhau thì đừng dùng cách này =))))))))) */

bool checkPrimeNumber(int n) // Hàm kiểm tra số nguyên tố 
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
		return true;
	}
	return false;
}

int countPrimeFromTwoPoints(int mat[][MAXCOL], int nRow, int nCol, int xA, int yA, int xB, int yB)
{
	int a[100];
	int h1 = 0, h2 = nRow - 1, c1 = 0, c2 = nCol - 1;
	int tmp = 0;
	// Lười code quá nên mình copy code xoắn ốc này của 28tech và có thay đổi một xíu hehe :> 
	while (h1 <= h2 && c1 <= c2)
	{
		//Xây dựng cạnh trên : hàng h1 từ cột c1 => cột c2 
		for (int i = c1; i <= c2; i++)
		{
			a[tmp++] = mat[h1][i];
		}
		//Tăng h1 để xây dựng cạnh bên phải, cột c2 từ hàng h1 tới hàng h2 
		h1++;
		for (int i = h1; i <= h2; i++)
		{
			a[tmp++] = mat[i][c2];
		}
		//giảm c2 để xây dựng cạnh dưới, hàng h2 từ c2 => cột c1 
		c2--;
		for (int i = c2; i >= c1; i--) {
			a[tmp++] = mat[h2][i];
		}
		//giảm h2 để xây dựng cạnh bên phải, cột c1 từ hàng h2 tới hàng h1 
		h2--;
		for (int i = h2; i >= h1; i--) 
    {
			a[tmp++] = mat[i][c1];
		}
		//tăng c1 
		++c1;
	}
	int soA = mat[xA][yA], soB = mat[xB][yB]; // Tìm 2 số A và B trước. 
	int VTsoA = 0, VTsoB = 0; int dem = 0, count = 0;
	for (int i = 0; i < tmp; i++) // Dò tìm vị trí của hai số A, B trong mảng một chiều. 
	{
		if (a[i] == soA)
		{
			VTsoA = i;
			dem++;
		}
		else if (a[i] == soB)
		{
			VTsoB = i;
			dem++;
		}
		if (dem == 2) // Khi đã tìm đủ 2 vị trí, bắt đầu tiến hành đếm SNT trên đường đi. 
		{
			if (VTsoA > VTsoB)
			{
				for (int i = VTsoB + 1; i < VTsoA; i++)
				{
					if (checkPrimeNumber(a[i]) == true)
					{
						count++;
					}
				}
				break;
			}
			else if (VTsoA < VTsoB)
			{
				for (int i = VTsoA + 1; i < VTsoB; i++)
				{
					if (checkPrimeNumber(a[i]) == true)
					{
						count++;
					}
				}
				break;
			}
		}
	}
	return count;
}
