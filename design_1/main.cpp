#include <iostream>

enum Judge
{
    OK = 0,
    NG = -1
};

enum Phase
{
    InputNum1 = 0,
    InputOperator,
    InputNum2,
    Calculate,
    OutputResult
};

int inputNum()
{
    int input;
    std::cin >> input;
    return input;
}

int inputOperator()
{
    char input;
    std::cin >> input;
    return (int)input;
}

Judge checkInput(int input, Phase phase)
{
    // qは終了
    if(input == 113){
        exit(0);
    }

    if(phase == InputNum1 || phase == InputNum2){

    }

    return OK;
}

int calculate(int input1, int input2, int ope)
{
    int result;

    if(ope == 43){
        result = input1 + input2;
    }else if(ope == 45){
        result = input1 - input2;
    }else if(ope == 42){
        result = input1 * input2;
    }else if(ope == 47){
        result = input1 / input2;
    }

    return result;
}

void outputResult(int result)
{
    std::cout << result << std::endl;
}

int main()
{
    Phase phase;
    int input1, input2;
    int ope;
    int result;

    while(1){
        phase = InputNum1;
        input1 = inputNum();
        checkInput(input1, phase);

        phase = InputOperator;
        ope = inputOperator();
        checkInput(ope, phase);

        phase = InputNum2;
        input2 = inputNum();
        checkInput(input2, phase);

        phase = Calculate;
        result = calculate(input1, input2, ope);

        phase = OutputResult;
        outputResult(result);
    }

    return 0;
}
