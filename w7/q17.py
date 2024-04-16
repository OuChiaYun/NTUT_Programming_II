def inversion_number_tworecurs(arr):

    return merge_sort(list(tuple(arr)), 0, len(arr)-1)


def merge_sort(arr_tmp, left, right):
    count = 0

    if left < right:
        mid = (left + right)//2

        # count += merge_sort(arr_tmp, left, mid) + \
        #     merge_sort(arr_tmp, mid+1, right)
        
        count += merge_sort(arr_tmp, left, mid)+ merge_sort(arr_tmp, mid+1, right)
        print("count : ",count)
        print(arr_tmp)

        tmp_arr = []
        tmp_count = 0
        tmp_start_l = left
        tmp_start_r = mid+1

        while tmp_start_l <= mid and tmp_start_r <= right:

            if (arr_tmp[tmp_start_l] <= arr_tmp[tmp_start_r]):

                tmp_arr.append(arr_tmp[tmp_start_l])
                tmp_start_l += 1
                n = tmp_start_r

            else:
                tmp_arr.append(arr_tmp[tmp_start_r])
                tmp_start_r += 1
                tmp_count += mid-tmp_start_l + 1
                n = tmp_start_l

        m = right if n == tmp_start_r else mid
        n = tmp_start_r if m == right else tmp_start_l
        
        for i in range(n,m+1,1):
            tmp_arr.append(arr_tmp[i])
        print(tmp_arr)
        arr_tmp[left:right+1] = tmp_arr[:len(tmp_arr)]

        return tmp_count + count

    return count

perm = []

# #perm = [12, 11, 13, 5, 6, 7]
perm=[3,1,9,8,9,2,2,7,6,5,4,1,4,3,5,3,1,9,8 ,9 ,2 ,2 ,7 ,6 ,5 ,4 ,1 ,4 ,3 ,5]

    
# 15
# 3 1 9 8 9 2 2 7 6 5 4 1 4 3 5
    
    
print("Permutation:", perm)
print('The inversion number of is', inversion_number_tworecurs(perm),'(binary)')