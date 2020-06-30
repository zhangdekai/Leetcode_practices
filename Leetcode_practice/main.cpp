//
//  main.cpp
//  Leetcode_practice
//
//  Created by zhang dekai on 2020/6/30.
//  Copyright © 2020 mr dk. All rights reserved.
//

#include <iostream>
#include <set>
#include <vector>
#include <unordered_map>

using namespace std;

#pragma mark 1：只出现一次的数字
/*
 
 leetcode:https://leetcode-cn.com/problems/single-number/
 
 给定一个非空整数数组，除了某个元素只出现一次以外，其余每个元素均出现两次。
 找出那个只出现了一次的元素。

 说明：

 你的算法应该具有线性时间复杂度。 你可以不使用额外空间来实现吗？

 示例 1:

 输入: [2,2,1]
 输出: 1
 示例 2:

 输入: [4,1,2,1,2]
 输出: 4
 
 */
/*
 思路：
 
 不使用额外空间，要求空间复杂度 O(1)，不申请额外空间
 
 异或解法：异或运算满足交换律，a^b^a=a^a^b=b,因此ans相当于nums[0]^nums[1]^nums[2]^nums[3]^nums[4].....
 然后再根据交换律把相等的合并到一块儿进行异或（结果为0），然后再与只出现过一次的元素进行异或，这样最后的结果就是，只出现过一次的元素
 
 （0^任意值=任意值）
 */

int singleNumber(int* nums, int numsSize){
    int temp = nums[0];
        if(numsSize > 1) {
            for(int i = 1; i < numsSize; i++) {
                temp = temp ^ nums[i];
            }
        }
        
    return temp;
}


// 利用C++ set容器，元素一加入，自动排序（升序），去重 特性 需要引入 #include<set>

int singleNumber1(vector<int>& nums){
    
    
    set<int> s1;
    int sum1 = 0,sum2 = 0;
    
    for (int i = 0; i < nums.size(); i++) {
        
        s1.insert(nums[i]);
        
        sum1 = sum1 + nums[i];
    }
    
    
    for (set<int>::iterator t = s1.begin(); t != s1.end(); t++) {
        printf("%d \n",*t);
        sum2 += *t;
    }
    
    return 2 * sum2 - sum1;
}

void testSingleNumber1(){
    
    vector<int>nums = {2,2,34,3,3};
    
    int num = singleNumber1(nums);
    
    printf("只出现一次的数字是:%d\n",num);
}


void testSingleNumber(){
    
    int nums[5] = {2,2,34,3,3};
    
    int num = singleNumber(nums, 5);
    
    printf("只出现一次的数字是:%d\n",num);
    
    
    testSingleNumber1();

}

#pragma mark 2: 多数元素
/*
 
 leetcode:https://leetcode-cn.com/problems/majority-element/solution/duo-shu-yuan-su-by-leetcode-solution/
 
 给定一个大小为 n 的数组，找到其中的多数元素。多数元素是指在数组中出现次数大于 ⌊ n/2 ⌋ 的元素。

 你可以假设数组是非空的，并且给定的数组总是存在多数元素。


 示例 1:

 输入: [3,2,3]
 输出: 3
 示例 2:

 输入: [2,2,1,1,1,2,2]
 输出: 2
 */

int majorityElement(vector<int>& nums) {
    
  set<int> s1;
  
    for (int i = 0; i < nums.size(); i++) {
      
      s1.insert(nums[i]);

  }
  
  int *temp1 = (int*)malloc(sizeof(int)*s1.size());
  int j = 0;
    int count =  int(nums.size() / 2);

  for (set<int>::iterator t = s1.begin(); t != s1.end(); t++) {
      int temp = 0;
      for (int i = 0; i < nums.size(); i++) {
          if (*t == nums[i]) {
              temp++;
          }
      }
      if (temp > count) {
          return *t;
      }
      temp1[j] = temp;
      j++;
  }
  

  return 0;

}

int majorityElement1(int* nums, int numsSize){
    
        
    set<int> s1;
    
    for (int i = 0; i < numsSize; i++) {
        
        s1.insert(nums[i]);

    }
    
    int *temp1 = (int*)malloc(sizeof(int)*s1.size());
    int j = 0;
    int count = numsSize / 2;

    for (set<int>::iterator t = s1.begin(); t != s1.end(); t++) {
        int temp = 0;
        for (int i = 0; i < numsSize; i++) {
            if (*t == nums[i]) {
                temp++;
            }
        }
        if (temp > count) {
            return *t;
        }
        temp1[j] = temp;
        j++;
    }
    
   
    
  
    return 0;
}

int majorityElement2(vector<int>& nums) {
    
    unordered_map<int,int> counts;
    
    int temp = 0, cnts = 0;
    
    for (int i = 0 ; i < nums.size(); i++) {
        
        counts[nums[i]]++;
        
        if (counts[nums[i]] > cnts) {
            temp = nums[i];//key
            cnts = counts[nums[i]];//value 次数
        }
    }
    
    if (cnts > (nums.size() / 2)) {
        return temp;
    }
    
    return 0;
}

void testmajorityElement(){
    int a[3] = {3,2,3};
    int temp = majorityElement1(a, 3);
    
    printf("1:最多的数字是:%d \n",temp);
    
    
    vector<int>s1 = {2,2,1,1,1,2,2};
    
    
//    int temp1 =  majorityElement1(s1);
    int temp1 =  majorityElement2(s1);

    printf("2:最多的数字是:%d \n",temp1);

}




int main(int argc, const char * argv[]) {
    // insert code here...
    std::cout << "Hello, World!\n";
    
    printf("你好啊\n");
    
    testSingleNumber();
    
    testmajorityElement();
    
    
        
    return 0;
}
