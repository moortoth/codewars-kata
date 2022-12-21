#include <stdlib.h>
#include <string.h>
#include <stdio.h>

char *add(const char *a, const char *b) 
{
    int len_a = strlen(a);
    int len_b = strlen(b);
    int max_len = len_a > len_b ? len_a : len_b;
    char* res = malloc(sizeof(char) * (max_len + 1));
    char mem = 0;

    for (int i = 0; i < max_len; ++i) {
        char term_a = len_a - 1 - i < 0 ? 0 : a[len_a - 1 - i] - '0';
        char term_b = len_b - 1 - i < 0 ? 0 : b[len_b - 1 - i] - '0';
        char sum = term_a + term_b + mem;
        res[max_len - 1 - i] = (sum % 10) + '0';
        mem = sum / 10;
    }

    res[max_len] = '\0';

    if (mem) {
        char* bigger_res = malloc((strlen(res) + 2) * sizeof(char));
        strcpy(bigger_res, "1");
        strcat(bigger_res, res);
        free(res);
        return bigger_res;
    }
    
    return res;
}

int main(int argc, char* argv[]) 
{
    // tester("1", "1", "2");
    //char* res1 = strsum("1", "1");
    // tester("123", "456", "579");  // 123 + 456 == 579
    //char* res2 = strsum("123", "456");
    // tester("888", "222", "1110");
    //char* res3 = strsum("888", "222");
    // tester("1372", "69", "1441");
    char *res_lead_zeros = strsum("00001", "9");
    char* res = strsum("36294500649", "5175666562665014609");
    //char* res_a = strsum("0", "0");
    char* res_b = strsum("99", "1");
//Expected:  5175666598959515258
//Submitted: 51756665989595152584
}