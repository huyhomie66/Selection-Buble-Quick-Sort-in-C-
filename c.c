#include <stdio.h>
// bài toán sắp xếp các phần tử trong mảng nhập vào theo tứ tự tăng dần
void input(int a[], int n);
void bubbleSort(int *a, int itemsCount);
void selectionSort(int *a, int itemsCount);
void quicksort0(int arr[], int a, int b);
void quickSort(int *a, int left, int right);
int partition(int *a, int left, int right, int pivot) ;
int main()
{
    int a[10000];   // đã khởi tạo 1 mảng tối đa là 10 phần tử trong hàm main
    int n;       // n là biến đếm mặc định trong hàm main
    input(a, n); //
    // selectionSort(a, n);
}
// sắp xếp tăng dần
void input(int a[], int n)
{ // đây là hàm input, chỉ viết thuật toán sắp xếp vào đây
    // giờ sẽ dùng sắp xếp nổi bọt để sắp xếp tăng dần các phần tử trong mảng nhập vào
    printf("nhập size của mảng: ");
    scanf("%d", &n);
    for (int i = 0; i < n; i++)
    {
        printf("nhập số phần tử của mảng : ");
        scanf("%d", &a[i]);
    }
    // đoạn này các phần tử chưa được sắp xếp
    printf("các phần tử của mảng là: ");
    for (int i = 0; i < n; i++)
    {
        printf("%d ", a[i]);
    }
    // giờ sẽ thêm thuật toán sắp xếp nổi bọt để sắp xếp các phần tử trong mảng

    //bubbleSort(a,n) ;// giờ sẽ truyền vào mảng a  và biến đếm n
    //selectionSort(a, n);
    // tiếp theo là sử dụng quit sort(sắp xếp nhanh)
    // quicksort0(a, 0, n - 1);
    quickSort(a, 0, n - 1);
    // chỉ được để 1 hàm để sắp xếp đừng có viết cả 3 vào, hàm quit sort có truyền tham số là
    // con trỏ a, số đầu , số cuối của mảng
    // có 2 hàm quit sort , nhầm lẫn sẽ public thêm vào code, tất cả gõ lệnh git clone + link github để down code về chạy.
    // đoạn này là sau khi sắp xếp nó sẽ hiện ra
    printf("\ncác phần tử của mảng sau khi sắp xếp là: ");
    for (int i = 0; i < n; i++)
    {
        printf("%d ", a[i]);
    }
}
// sắp xếp lựa chọn
void selectionSort(int *a, int itemsCount)
{
    int minIndex, temp;
    for (int i = 0; i < itemsCount - 1; i++)
    {
        minIndex = i;
        for (int j = i + 1; j < itemsCount; j++)
        {
            if (a[minIndex] > a[j])
            {
                minIndex = j;
            }
        }
        if (minIndex > i)
        {
            temp = a[minIndex];
            a[minIndex] = a[i];
            a[i] = temp;
        }
    }
}
//sắp xếp nổi bọt
void bubbleSort(int *a, int itemsCount) // tham số truyền vào là con trỏ a(trả về giá trị của a dưới mọi định dạng vd: mảng, int ,float...)
{                                       // ngoài con trỏ a còn biến đếm
    int temp;
    for (int i = 0; i < itemsCount - 1; i++)
    {
        for (int j = 0; j < itemsCount - 1 - i; j++)
        {
            if (a[j] > a[j + 1])
            {
                temp = a[j];
                a[j] = a[j + 1];
                a[j + 1] = temp;
            }
        }
    }
}

//sắp xếp nhanh ( hàm này truyền tham số là mảng a)
void swap(int arr[], int i, int j)
{
    int temp = arr[j];
    arr[j] = arr[i];
    arr[i] = temp;
}

void quicksort0(int arr[], int a, int b)
{
    if (a >= b)
        return;

    int key = arr[a];
    int i = a + 1, j = b;
    while (i < j)
    {
        while (i < j && arr[j] >= key)
            --j;
        while (i < j && arr[i] <= key)
            ++i;
        if (i < j)
            swap(arr, i, j);
    }
    if (arr[a] > arr[i])
    {
        swap(arr, a, i);
        quicksort0(arr, a, i - 1);
        quicksort0(arr, i + 1, b);
    }
    else
    {
        quicksort0(arr, a + 1, b);
    }
}

// sắp sếp nhanh ( hàm này truyền tham số là  con trỏ a)
int partition(int *a, int left, int right, int pivot)
{
    int leftIndex = left - 1;
    int rightIndex = right;
    int temp;
    while (1)
    {
        while (a[++leftIndex] < pivot)
            ;
        while (rightIndex > 0 && a[--rightIndex] > pivot)
            ;
        if (leftIndex >= rightIndex)
        {
            break;
        }
        else
        {
            temp = a[leftIndex];
            a[leftIndex] = a[rightIndex];
            a[rightIndex] = temp;
        }
    }
    return leftIndex;
}
void quickSort(int *a, int left, int right)
{
    if (right <= left)
    {
        return;
    }
    int pivot = a[right];
    int partitionIndex = partition(a, left, right, pivot);
    a[right] = a[partitionIndex];
    a[partitionIndex] = pivot;
    quickSort(a, left, partitionIndex - 1);
    quickSort(a, partitionIndex + 1, right);
}
