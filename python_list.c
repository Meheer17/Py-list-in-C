#include <stdio.h>
#include <stdlib.h>
#include "list.h"

typedef struct{
    int length;
    unsigned char num[];
} List;

int main() 
{
    List *list = (List *)malloc(sizeof(List));
    list->length = 0;
    int ch = 0;
    while(ch < 15)
    {
        printf("\n1. Add New Element \t2. Print The Number Of Elements \n3. Print Elements \t4. Clear List \n5. Pop last Element \t6. Count the Occurrence \n7. Find the Index \t8. Min/Max \n9. Reverse \t\t10. Extend By initilizing a list \n11. Remove Element \t12. Insert \n13. Sort \n");
        scanf("%d", &ch);
        switch(ch){
            case 1:
                printf("Enter the New Element Value: ");
                int value;
                scanf("%d", &value);
                push(list, value);
                break;
            case 2:
                printf("\nThe Length is: %d\n", len(list));
                break;
            case 3:
                printf("\n[");
                for(int i = 0; i < list->length; i++) printf(" %d, ", list->num[i]);
                printf("] \n");
                break;
            case 4:
                clear(list);
                break;
            case 5:
                printf("The Element poped is: %d\n", pop(list));
                break;
            case 6:
                int var;
                printf("The occurrence of: ");
                scanf("%d", &var);
                printf("\nThe Occurrence is: %d\n", count(list, var));
                break;
            case 7:
                int finnd;
                printf("Find the index of: ");
                scanf("%d", &finnd);
                if(ind(list, finnd) == -1) printf("\n Not found in the List");
                else printf("The Index is: %d\n", ind(list, finnd));
                break;
            case 8:
                printf("The Max in the list is %d, and the Min in the list is %d\n", max(list), min(list));
                break;
            case 9:
                reverse(list);
                break;
            case 10:
                printf("Number of Elements: ");
                int va;
                scanf("%d", &va);
                List *newlist = (List *)malloc(sizeof(List));
                newlist->length = 0;
                for(int i = 0; i < va; i++){
                    printf("Value: ");
                    int v;
                    scanf("%d", &v);
                    push(newlist, v);
                }
                extend(list, newlist);
                free(newlist);
                break;
            case 11:
                int rem_val;
                printf("The value to be Removed: ");
                scanf("%d", &rem_val);
                rem(list, rem_val);
                break;
            case 12: 
                int ins_val, ins_ind;
                printf("The index and value sep by space: ");
                scanf("%d %d", &ins_ind, &ins_val);
                insert(list, ins_ind, ins_val);
                break;
            case 13:
                int *arr;
                arr = (int*)malloc(list->length * sizeof(int));
                for(int i = 0; i < list->length; i++){
                    arr[i] = list->num[i];
                }
                quickSort(arr, 0, list->length - 1);
                for(int i = 0; i < list->length; i++){
                    list->num[i] = arr[i];
                }
                free(arr);
                break;
            default:
                printf("Not a valid choice\n");
                break;
        };
    }
    free(list);
    return 0;   
}