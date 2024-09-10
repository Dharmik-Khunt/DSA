#include <iostream>
using namespace std;
int front = -1, rear = -1;

void enqueue(int num, int n, int *a)
{
    rear = rear + 1;
    if (rear == n)
    {
        rear = 0;
    }
    else
    {
        a[rear] = num;
    }
    if (front == -1)
    {
        front = 0;
    }
}

int dequeue(int *a, int n)
{
    if (front == -1)
    {
        cout << "queue is empty";
    }
    else
    {
        int x;
        x = a[front];
        if (front == rear)
        {
            front = -1;
            rear = -1;
        }
        else
        {
            front = front + 1;
        }
        if (front == n)
        {
            front = 0;
        }
        return x;
        
    }
}
int main()
{
    int n;
    cout << "Enter the size of the array:";
    cin >> n;
    int a[n];
    int i, j, iteration;
    cout << "Enter the iteration of the loop:";
    cin >> iteration;

    int choice;
      int ans[n];
    
    for ( i = 0,j=0; i < iteration; i++)
    {
        cout<<endl;
        cout << "Enter the choice:"<<endl;
        cin >> choice;

        switch(choice)
        {
            case 1:
            int num;
            cout<<"Enter the number :"<<endl;
            cin>>num;
            enqueue(num , n ,a );
            break;

            case 2:
          
            ans[j]=dequeue(a,n);
            j++;
            break;

        }
    }
    for(i=0; i<j; i++)
    {
        cout<<ans[i]<<endl;
    }
    cout<<"Prepared by 23CE058 Dharmik";
    
}