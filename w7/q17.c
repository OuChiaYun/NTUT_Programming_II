#include <stdio.h>

int merge_sort(int arr_tmp[], int left, int right)
{

    int count = 0;

    if (left < right)
    {
        int mid = (left + right) / 2; // 2

        count += merge_sort(arr_tmp, left, mid) + merge_sort(arr_tmp, mid + 1, right);

        int tmp_arr[150] = {0};
        int tmp_count = 0;
        int tmp_start_l = left;
        int tmp_start_r = mid + 1;
        int i = 0;
        int n = 0;

        while ((tmp_start_l <= mid) && (tmp_start_r <= right))
        {

            if (arr_tmp[tmp_start_l] <= arr_tmp[tmp_start_r])
            {

                tmp_arr[i] = (arr_tmp[tmp_start_l]);
                tmp_start_l += 1;
                n = tmp_start_r;
                i++;
                // printf("ads\n");
            }
            else
            {
                tmp_arr[i] = (arr_tmp[tmp_start_r]);
                tmp_start_r += 1;
                tmp_count += mid - tmp_start_l + 1;
                n = tmp_start_l;
                i++;
                // printf("kfo\n");
            }
        }

        int m;

        if (n == tmp_start_r)
        {
            m = right;
        }
        else
        {
            m = mid;
        }

        if (m == right)
        {
            n = tmp_start_r;
        }
        else
        {
            n = tmp_start_l;
        }

        for (int k = n; k < m + 1; k++)
        {
            tmp_arr[i] = (arr_tmp[k]);
            i++;
        }

        // for (int g = 0; g < 20; g++) //
        // {
        //     printf("%d ", tmp_arr[g]);
        // }
        // printf("\n"); //

        int f = 0;
        for (int k = left; k < right + 1; k++)
        {
            if (f >= i)
            {
                break;
            }
            else
            {
                arr_tmp[k] = tmp_arr[f];
            }
            f++;
            // printf("%d ", arr_tmp[k]);
        }
        // printf("\n");
        // printf("all : %d\n",tmp_count + count);

        return tmp_count + count;
    }
    return count;
}

int inversion_number_tworecurs(int arr[], int n)
{
    return merge_sort(arr, 0, n - 1);
}

int main()
{
    int perm[150] = {0};
    int n = 15;

    scanf("%d",&n);

    for(int j = 0;j<n;j++){
        scanf("%d",&perm[j]);
    }
    // printf("Permutation:", perm);
    printf("%d\n", inversion_number_tworecurs(perm, n));
}