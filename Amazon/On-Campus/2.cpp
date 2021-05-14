/*
Amazon - Onsite
Question 1: Students are standing in the row. Given an input of weights of children find the position of a child, such that all students lighter to him are in his left and the ones heavier than him are in his right.
There must be atleast a children to it's left and right. If there is not such position return -1.
Input: 56 54 63 74 69
Output: 3 (1-index based)
*/


/*
My insights to this probles:
    - This problem becomes interesting when there are Q queries and a search space is given [L,R].
    - This problem then can be easily solved using Segment Trees.
    - This can be a expected follow up.
*/


int GetPosition(vector<int> weight){
    int n=weight.size();
    int leftMax[n], rightMin[n];
    leftMax[0]=weight[0];
    rightMin[n-1]=weight[n-1];

    for(int i=1;i<n;i++){
        leftMax[i]=max(leftMax[i-1],weight[i]);
    }
    for(int i=n-2;i>=0;i--){
        rightMin[i]=min(rightMin[i+1],weight[i]);
    }

    for(int i=1;i<n-1;i++){
        if(weight[i]<rightMin[i+1] and weight[i]>leftMax[i-1]) return i+1;
    }
    return -1;
}
