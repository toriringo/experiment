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

double inputNum()
{
    double input;
    std::cin >> input;
    return input;
}

char inputOperator()
{
    char input;
    std::cin >> input;
    return input;
}

Judge checkNum(const double input, const Phase phase)
{
    // qは終了
    // doubleにqを入力しても113にならないので、対策が必要
    if(static_cast<int>(input) == 113){
        exit(0);
    }

    if(phase == InputNum1 || phase == InputNum2){
    }

    return OK;
}

Judge checkOperator(const char input, const Phase phase)
{
    // qは終了
    if(static_cast<int>(input) == 113){
        exit(0);
    }

    if(phase == InputNum1 || phase == InputNum2){
    }

    return OK;
}

double calculate(const double input1, const double input2, const char ope)
{
    double result;

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

void outputResult(double result)
{
    std::cout << result << std::endl;
}

int main()
{
    Phase phase;
    double input1, input2;
    char ope;
    double result;

    while(1){
        phase = InputNum1;
        input1 = inputNum();
        checkNum(input1, phase);

        phase = InputOperator;
        ope = inputOperator();
        checkOperator(ope, phase);

        phase = InputNum2;
        input2 = inputNum();
        checkNum(input2, phase);

        phase = Calculate;
        result = calculate(input1, input2, ope);

        phase = OutputResult;
        outputResult(result);
    }

    return 0;
}
