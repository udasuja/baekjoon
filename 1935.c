/*
풀이
값을 저장하는 모든 변수는 double로 설정(문자는 제외)
출력은 %.2lf로 소숫점 둘째 자리까지 출력한다.

후위표기식에 대한 문자열을 배열에 저장한다. -> A배열
그 후 각 피연산자에 대한 값을 또 다른 배열에 저장한다. -> B배열

A배열에 있는 피연산자를 차례대로 stack에 push한다.
이때 A배열에 있는 피연산자는 문자이므로
B[문자-'A']로 문자인 피연산자에 대한 값을 넣음

그리고 연산자가 나오면 stack에 있는 피연산자를 2개 pop한다.
그 피연산자를 차례대로 각각 변수 a,b에 넣는다.

switch문으로 각 연산자에 대한 연산을 한다(b '연산자' a). 
그리고 이 값을 stack에 push한다.
이 과정을 A배열의 널문자에 다다를 때까지 반복한다.

널문자에 도달하면 stack에는 최종 결과값만 들어있을 것이다.
이 값을 pop하여 결과값을 출력한다.

이때 연산자 문자 +, -, *, /는 각각 -1부터 -4에 대응된다.
*/

