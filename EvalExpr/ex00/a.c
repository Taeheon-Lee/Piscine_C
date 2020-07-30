/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   a.c                                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlee <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/10 23:11:48 by tlee              #+#    #+#             */
/*   Updated: 2019/11/10 23:42:24 by tlee             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <string.h>

typedef enum {false, true} bool;

#define ARRAY_SIZE 200

char input[ARRAY_SIZE] = {0};

int inputLength = 0;

void printInputArray() {
    for (int i =0; i < inputLength; i++) {
        printf("%c", input[i]);
    }
    printf("\n");
}

int array_len(argv[1])
{
	int len;

	len = 0;
	while (argv[1][len])
		len++;
	return (len);
}

int fundamentalOperation(char localValue[ARRAY_SIZE], int localCount) 
{
    int  v[ARRAY_SIZE] = {0};
    int  vIdx = 0;
    char con[ARRAY_SIZE] = {0};
    int  conIdx = 0;
    int  sqr = 0;
    bool hasDivMultip = false; 
	for (int j = 0; j < localCount; j++) 
	{
        if ('0' <= localValue[j] && localValue[j] <= '9') 
		{
            sqr *= 10;
            sqr += localValue[j] - '0';
        }
		else if (localValue[j] == '-' || localValue[j] == '+') 
		{
            v[vIdx] = sqr;      
			sqr = 0;            
			vIdx++;                        
            if (hasDivMultip) 
			{	
				int tmp = 0;
                if (con[conIdx-1] == '*')
                    tmp = v[vIdx-2] * v[vIdx-1];
				else if (con[conIdx-1] == '/')
                    tmp = v[vIdx-2] / v[vIdx-1];
                hasDivMultip = false;
                con[conIdx-1] = 0;
                conIdx--;
                v[vIdx-1] = 0;
                v[vIdx-2] = 0;
                vIdx -= 2;
                v[vIdx] = tmp;
                vIdx ++;
            }
            con[conIdx] = localValue[j];
            conIdx++;
		}
		else if (localValue[j] == '*' || localValue[j] == '/') 
		{
            v[vIdx] = sqr;
            sqr = 0;
            vIdx++;
            if (hasDivMultip) 
			{
                int tmp = 0;
                if (con[conIdx-1] == '*')
                    tmp = v[vIdx-2] * v[vIdx-1];
                else if (con[conIdx-1] == '/') 
                    tmp = v[vIdx-2] / v[vIdx-1];
                con[conIdx-1] = 0;
                conIdx--;
                v[vIdx-1] = 0;
                v[vIdx-2] = 0;
                vIdx -= 2;
                v[vIdx] = tmp;
                vIdx ++;
            }
            con[conIdx] = localValue[j];
            conIdx++;       
            hasDivMultip = true;
        }
        if (j == localCount-1) 
		{
            v[vIdx] = sqr;
            sqr = 0;
            vIdx++;
            
            if (hasDivMultip) 
			{
                int tmp = 0;
                if (con[conIdx-1] == '*') 
				{
                    tmp = v[vIdx-2] * v[vIdx-1];
                }
				else if (con[conIdx-1] == '/') 
				{
                    tmp = v[vIdx-2] / v[vIdx-1];
                }
                hasDivMultip = false;
                con[conIdx-1] = 0;
                conIdx--;
                v[vIdx-1] = 0;
                v[vIdx-2] = 0;
                vIdx -= 2;
                v[vIdx] = tmp;
                vIdx ++;
            }
        }
    }
    int result = v[0];
    for (int i =0; i < conIdx; i++) 
	{
        if (con[i] == '+') 
		{
            result += v[i+1];
        }
		else if (con[i] == '-') 
		{
            result -= v[i+1];
        }
    }
    return result;
}

void bracketOperation() 
{
    int newForm[ARRAY_SIZE] = {0};
    int newFormIdx = 0;
    char localValue[ARRAY_SIZE] = {0};
    int localCount = 0;
    int localStart = 0;
    int localEnd = 0;
    int localResult = 0;
    for (int i = 0; i < inputLength; i++) 
	{
        if (input[i] == '(') 
		{
            memset(&localValue[0], 0, sizeof(localValue));
            localCount = 0;
            localStart = i;
        }
		else if (input[i] == ')') 
		{
            localResult = fundamentalOperation(localValue, localCount);
            localEnd = i;
            for (int j = 0; j < ARRAY_SIZE; j++) 
			{
                if (j < localStart) 
				{
                    newForm[newFormIdx] = input[j];
                    newFormIdx++;
                }
				else if (j == localStart) 
				{
                    char localResultArr[11] = {0};
                    sprintf(localResultArr, "%d", localResult);
                    for (int k = 0; k < 11; k++) 
					{
                        if (localResultArr[k] != 0) 
						{
                            newForm[newFormIdx] = localResultArr[k];
                            newFormIdx++;
                        }
						else 
						{
                            break;
                        }
                    }
                }
				else if (j > localEnd && input[j] != 0) 
				{
                    newForm[newFormIdx] = input[j];
                    newFormIdx++;
                }
            }
            break;
        }
		else 
		{
            localValue[localCount] = input[i];
            localCount++;
        }
    }
    memset(&input[0], 0, sizeof(input));
    inputLength = 0;
    for (int i = 0; i < ARRAY_SIZE; i++) 
	{
        if (newForm[i] == 0) 
		{
            break;
        }
		else 
		{
            input[i] = newForm[i];
            inputLength++;
        }
    }
}

int main(int argc, const char **argv) 
{
            }else {
                while (1) { // 괄호를 다 풀어낼 때 까지 무한반복한다.
                    bool hasBracket = false;
                    for (int i = 0; i < inputLength; i++) { // 괄호를 가지고 있는지 확인하고,
                        if (input[i] == '(') {
                            hasBracket = true; // 있으면 hasBracket를 참으로 변경
                            break;
                        }
                    }
                    if (hasBracket) { // hasBracket가 참일 경우(괄호를 가지고 있을 경우)
                        bracketOperation(); // 괄호 하나를 풀어내고
                        printInputArray(); // 결과를 출력
                    }else { // 괄호가 없을 경우, 반복문을 벗어난다.
                        break;
                    }
                }
                // 기타 잔여 사칙연산을 수행한다.
                int result = fundamentalOperation(input, inputLength);
                printf("결과는 %d입니다.\n", result); // 결과 출력
            }
        }
        // 배열의 모든 데이터를 0으로 초기화
        memset(&input[0], 0, sizeof(input));
        inputLength = 0;
    }
    printf("종료합니다.\n");
    
    
    return 0;
}
