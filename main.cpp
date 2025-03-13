#include <iostream>  
#include <locale.h>
#include <math.h>

using namespace std;

int switchMainMenu;
int switchSubsMenu;
int modularIncrementCounter  = 0;
double operationResult;
double historyDataArray[10] = {0};
double doubleNum1;
double doubleNum2;
int intNum1;
int intNum2;

//Utilitários
void pressAnyKey();
void clearTerminal();

//Sistema de histórico
void addonHistory(double historyInsert);
void showHistory();
void clearHistory();
double useMemoValue();
double memoOrNewValue();

// Operações Simples
void sum();
void sub();
void mult();
void div();

//Operações avançadas
void powe();
void sqrte();
void fator();
int verifyAngle(double angleToVerify);
void sine();
void cosine();
void tangent();
void mod();

//Menus
void mainMenu();
void basicOperationsMenu();
void advancedOperationsMenu(); 

int main() {
	setlocale(LC_ALL, "Portuguese");
	
	while(true) {
		mainMenu();

		if(switchMainMenu == 4) {
			break;
		}

		switch (switchMainMenu) {
			case 1: 
				basicOperationsMenu();
				switch (switchSubsMenu) {
					case 1:
						sum();
						break;
						
					case 2:
						sub();
						break;
						
					case 3:
						mult();
						break;
						
					case 4:
						div();
						break;	
						}
			break;
				
			case 2:
				advancedOperationsMenu();
				switch (switchSubsMenu) {
					case 1:
						powe();
						break;
	
					case 2:
						sqrte();
						break;

					case 3:
						fator();
						break;

					case 4:
						sine();
						break;
	
					case 5:
						cosine();
						break;
	
					case 6:
						tangent();
						break;
					
					case 7:
						mod();
						break;

					}
			break;	

			case 3:
				clearTerminal();
				showHistory();
				cout << endl;
				clearHistory();
			break;
		}
		pressAnyKey();
	}
	return 0;
}

void pressAnyKey() {	
		cout << endl << endl << "Pressione Enter para continuar..." << endl;
		cin.ignore();
		cin.get();
}

void clearTerminal() {
	#if defined(_WIN32) || defined(_WIN64)
			system("cls"); 
	#elif defined(__linux__) || defined(__unix__) || defined(__APPLE__)
			system("clear");
	#else
			cout << "Não foi pssível limpar a tela nesse OS." << endl;
	#endif
}

void addonHistory(double historyInsert) {
	historyDataArray[modularIncrementCounter] = historyInsert;
	modularIncrementCounter = (modularIncrementCounter + 1) % 10;
}

void showHistory() {
	cout << "\nOs últimos 10 resultados são: \n";
	for(int i = 0; i < 10; i++) {
		cout << i + 1 << ". " << historyDataArray[i] << endl;
	}
}

void clearHistory() {
	char verifyToClearHistory = ' '; 
	cout << "Deseja limpar o histórico? " << endl << "[S] Sim" << endl << "[N] Não" << endl;
	cin >> verifyToClearHistory;

	while(verifyToClearHistory != 's' && verifyToClearHistory != 'S' && verifyToClearHistory != 'n' && verifyToClearHistory != 'N') {
		cout << "Valor inválido!\nDeseja limpar o histórico? " << endl << "[S] Sim" << endl << "[N] Não" << endl;
		cin >> verifyToClearHistory;
	}
	
	if(verifyToClearHistory == 's' || verifyToClearHistory == 'S') {
		for(int i = 0; i < 10; i++) {
			historyDataArray[i] = 0;
		}
	}
	modularIncrementCounter = 0;
}

double useMemoValue() {
	int chooseOnHistory;
	cout << "Qual valor deseja usar?" << endl;
	showHistory();
	cin >> chooseOnHistory;
	return historyDataArray[chooseOnHistory - 1];
}

double memoOrNewValue() {
	double value;
	int switchValueMenu = 0;

	cout << "O Que deseja fazer?" << endl << "1 - Usar um novo valor." << endl << "2 - Usar um valor da memória." << endl;
	cin >> switchValueMenu;
	while(switchValueMenu != 1 && switchValueMenu != 2) {
		cout << "Valor inválido! " << endl << "O Que deseja fazer?" << endl << "1 - Usar um novo valor." << endl << "2 - Usar um valor da memória." << endl;
		cin >> switchValueMenu;
	}

	switch(switchValueMenu) {
		case 1:
			cout << "Insira o valor: ";
			cin >> value;
			clearTerminal();
			return value;
			break;

		case 2:
			clearTerminal();
			return useMemoValue();
			break;
	}
}

void sum() {
	cout << "Insira o primeiro valor: ";
	doubleNum1 = memoOrNewValue();
	cout << "Insira o segundo valor: ";
	doubleNum2 = memoOrNewValue();
	
	operationResult = doubleNum1 + doubleNum2;
	cout << "O resultado da soma de " << doubleNum1 << " + " << doubleNum2 << " = " << operationResult;
	addonHistory(operationResult);
}

void sub() {
	cout << "Insira o primeiro valor: ";
	doubleNum1 = memoOrNewValue();
	cout << "Insira o segundo valor: ";
	doubleNum2 = memoOrNewValue();

	operationResult = doubleNum1 - doubleNum2;
	cout << "O resultado da subtração de " << doubleNum1 << " - " << doubleNum2 << " = " << operationResult;
	addonHistory(operationResult);
}

void mult() {
	cout << "Insira o primeiro valor: ";
	doubleNum1 = memoOrNewValue();
	cout << "Insira o segundo valor: ";
	doubleNum2 = memoOrNewValue();

	operationResult = doubleNum1 * doubleNum2;
	cout << "O resultado da multiplicação de " << doubleNum1 << " * " << doubleNum2 << " = " << operationResult;
	addonHistory(operationResult);
}

void div() {
	cout << "Insira o dividendo: ";
	doubleNum1 = memoOrNewValue();
	cout << "Insira o divisor (!= 0): ";
	doubleNum2 = memoOrNewValue();

	while(doubleNum2 == 0) {
		clearTerminal();
		cout << "O Divisor, não pode ser 0!\nInsira outro valor: ";
		doubleNum2 = memoOrNewValue();
	}
	operationResult = doubleNum1 / doubleNum2;
	cout << "O resultado da divisão de " << doubleNum1 << " / " << doubleNum2 << " = " << operationResult;
	addonHistory(operationResult);
}

void powe() {
	cout << "Insira a base: ";
	doubleNum1 = memoOrNewValue();
	cout << "Insira o expoente: ";
	doubleNum2 = memoOrNewValue();

	operationResult = pow(doubleNum1, doubleNum2);
	cout << "O resultado da potência de " << doubleNum1 << " elevado a " << doubleNum2 << " = " << operationResult;
	addonHistory(operationResult);
}

void sqrte() {
	cout << "Insira o valor: ";
	doubleNum1 = memoOrNewValue();

	operationResult = sqrt(doubleNum1);
	cout << "O resultado da raiz quadrada de " << doubleNum1 << " = " << operationResult;
	addonHistory(operationResult);
}

void fator() {
	cout << "Insira o valor: ";
	doubleNum1 = memoOrNewValue();

	while(doubleNum1 < 0) {
		clearTerminal();
		cout << "O Valor inserido tem que ser positivo!\nInsira outro valor: " << endl;
		doubleNum1 = memoOrNewValue();
	}
	
	while(trunc(doubleNum1) != doubleNum1) {
		clearTerminal();
		cout << "O Valor inserido tem que ser inteiro!\nInsira outro valor: " << endl;
		doubleNum1 = memoOrNewValue();
	}
	
	operationResult = 1;
	for(int i = doubleNum1; i > 0; i--) {
		operationResult *= i;
	} 
	cout << "O resultado do fatorial de " << doubleNum1 << " = " << operationResult;
	addonHistory(operationResult);
}

int verifyAngle(double angleToVerify) {
	while(trunc(angleToVerify) != angleToVerify) {
		clearTerminal();
		cout << "Insira um valor inteiro: ";
		doubleNum1 = memoOrNewValue();
	}

	while(angleToVerify >= 178 || angleToVerify <= 1) {
		clearTerminal();
		cout << "Valor inválido, insira um valor válido: (1° a 178°)";
		doubleNum1 = memoOrNewValue();
	}

	return angleToVerify;
}

void sine() {
	cout << "Insira o valor do ângulo: ";
	doubleNum1 = memoOrNewValue();

	double radians = verifyAngle(doubleNum1) * (3.14 / 180);
	operationResult = sin(radians);
	cout << "O seno do ângulo de " << verifyAngle(doubleNum1) << "° = " << operationResult;
	addonHistory(operationResult);
}

void cosine() {
	cout << "Insira o valor do ângulo: ";
	doubleNum1 = memoOrNewValue();

	double radians = verifyAngle(doubleNum1) * (3.14 / 180);
	operationResult = cos(radians);
	cout << "O cosseno do ângulo de " << verifyAngle(doubleNum1) << "° = " << operationResult;
	addonHistory(operationResult);
}

void tangent() {
	cout << "Insira o valor do ângulo: ";
	doubleNum1 = memoOrNewValue();

	double radians = verifyAngle(doubleNum1) * (3.14 / 180);
	operationResult = tan(radians);
	cout << "A tangente do ângulo de " << verifyAngle(doubleNum1) << "° = " << operationResult;
	addonHistory(operationResult);
}

void mod() {
	cout << "Insira o dividendo: ";
	intNum1 = memoOrNewValue();
	cout << "Insira o divisor (!= 0): ";
	intNum2 = memoOrNewValue();

	while(intNum2 == 0) {
		clearTerminal();
		cout << "O Divisor, não pode ser 0!\nInsira outro valor: ";
		intNum2 = memoOrNewValue();
	}

	operationResult = intNum1 % intNum2;
	cout << "O resto da divisão de " << intNum1 << " por " << intNum2 << " = " << operationResult;
	addonHistory(operationResult);
}

void mainMenu() {
	clearTerminal();
	cout << "Escolha a operação desejada:" << endl;
	cout << "[1] Operações Básicas" << endl;
	cout << "[2] Operações Avançadas" << endl;
	cout << "[3] Histórico" << endl;
	cout << "[4] Sair" << endl;
	cin >> switchMainMenu;

	while (switchMainMenu < 1 || switchMainMenu > 4) {
			cout << "Valor inválido! Insira um número de 1 a 3: " << endl;
			cin >> switchMainMenu;
	}
	clearTerminal();
}

void basicOperationsMenu() {
		clearTerminal();
    cout << "Escolha a operação básica desejada:" << endl;
    cout << "[1] Soma" << endl;
    cout << "[2] Subtração" << endl;
    cout << "[3] Multiplicação" << endl;
    cout << "[4] Divisão" << endl;
    cin >> switchSubsMenu;

    while (switchSubsMenu < 1 || switchSubsMenu > 4) {
        cout << "Valor inválido! Insira um número de 1 a 4: " << endl;
        cin >> switchSubsMenu;
    }
		clearTerminal();
}

void advancedOperationsMenu() {
	clearTerminal();
	cout << "Escolha a operação desejada: " << endl;
	cout << "[1] Potência. " << endl;
	cout << "[2] Raiz Quadrada." << endl;
	cout << "[3] Fatorial." << endl;
	cout << "[4] Seno." << endl;
	cout << "[5] Cosseno. " << endl;
	cout << "[6] Tangente. " << endl;
	cout << "[7] Módulo." << endl;
	cin >> switchSubsMenu;

    while (switchSubsMenu < 1 || switchSubsMenu > 7) {
        cout << "Valor inválido! Insira um número de 1 a 7: " << endl;
        cin >> switchSubsMenu;
    }
		clearTerminal();
}