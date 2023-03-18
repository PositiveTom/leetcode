#include <iostream>

typedef struct Node
{
    int value = 0;
    struct Node* next = NULL;
}myNode, *myNodePtr;

template<class K, typename T>
T AddTwoNums(T n1ptr, T n2ptr)
{
    T result_list_ptr = new K;
    T remeber_result = result_list_ptr;

    bool add_one_flag = false;
    for(;n1ptr||n2ptr;)
    {
        //  判断上一次是否有进位
        if(add_one_flag)
        {
            if(n1ptr && n2ptr)
                result_list_ptr->value = (n1ptr->value + n2ptr->value) % 10 + 1;
            else if(n1ptr)
                result_list_ptr->value = (n1ptr->value ) % 10 + 1;
            else
                result_list_ptr->value = (n2ptr->value ) % 10 + 1;
            add_one_flag = false;
        }
        else
        {
            if(n1ptr && n2ptr)
                result_list_ptr->value = (n1ptr->value + n2ptr->value) % 10 ;
            else if(n1ptr)
                result_list_ptr->value = (n1ptr->value ) % 10;
            else
                result_list_ptr->value = (n2ptr->value ) % 10;
        }
        //  判断当前步加法是否产生进位
        if(n1ptr && n2ptr && (n1ptr->value + n2ptr->value >= 10)) add_one_flag = true;
        
        //  更新链表指针
        if(n1ptr->next)
            n1ptr = n1ptr->next;
        else
            n1ptr = NULL;

        if(n2ptr->next)
            n2ptr = n2ptr->next;
        else
            n2ptr = NULL;
        
        //  针对 两个树组都遍历到
        if(!n1ptr && !n2ptr && add_one_flag)
        {            
            result_list_ptr->next = new K;
            result_list_ptr = result_list_ptr->next;
            result_list_ptr->value = 1;
        }
        else if( !n1ptr && !n2ptr && !add_one_flag)
        {
            break;
        }
        else
        {
            result_list_ptr->next = new K;
            result_list_ptr = result_list_ptr->next;            
        }
    }
    return remeber_result;
}


int main(int argc, char** argv)
{
    myNode number1;
    number1.value = 2;
    myNode sub_number1;
    sub_number1.value =4;
    myNode sub_sub_number1;
    sub_sub_number1.value =3;
    number1.next = &sub_number1;
    // sub_number1.next = &sub_sub_number1;

    myNode number2;
    number2.value = 5;
    myNode sub_number2;
    sub_number2.value =6;
    myNode sub_sub_number2;
    sub_sub_number2.value =4;
    number2.next = &sub_number2;
    sub_number2.next = &sub_sub_number2;

    myNodePtr result = AddTwoNums<myNode>(&number1, &number2);
    // result = &number2;
    while(result)
    {
        std::cout << result->value << std::endl;
        result = result->next;
    }

    return 0;
}