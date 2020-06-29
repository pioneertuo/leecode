//给定一个未经排序的整数数组，找到最长且连续的的递增序列，并返回该序列的长度。

//方法一：基本思想：一次遍历，判断是否和后续元素发生逆序。只不过需要注意一下是顺序的特殊情况以及长度为0和1的时候的情况即可。


int findLengthOfLCIS(int* nums, int numsSize)
{
    int max=0,count=1,i;//对于序列的长度，至少会达到1
    if(numsSize==0)//考虑到极端情况
        return 0;
    for(i=0;i<numsSize-1;i++)
    {
        if(nums[i]<nums[i+1])//经过试验，相同的元素不算入递增
                count++;
        else//逆序的情况
        {
            if(count>max)
            {
                max=count;
            }
            count=1;
        }
    }
    
    if(count>max)//防止全部顺序，不出现逆序的情况
        max=count;
    return max;
}
