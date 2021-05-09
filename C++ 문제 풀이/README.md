# C++ 코딩 테스트 준비
[출처- BlockDMask](#https://blockdmask.tistory.com/)

## 목차
  - [String](#String)
  - [Vector](#Vector)

### String
  - `문자열 생성`
    - `string str = "문자열";` : 문자열 생성
    - `string str("문자열");` : 문자열 생성
    - `string str("복사할 문자열");` : 문자열 생성
  - `str.push_back('문자')` : 문자열 뒤에 문자 추가
  - `str.pop_back()` : 문자열 맨 뒤에 문자 삭제
  - `문자열 크기`
    - `str.size()` : 문자열 크기
    - `str.length()` : 문자열 크기
    - `str.resize(사이즈 크기,'대체 문자')`: 문자열의 사이즈 크기 조절(예제 참조)
  - `str.clear()` : 문자열 비우기
  - `str.substr(시작 idx,길이)` : 시작 idx부터 길이만큼 문자열 반환(범위를 벗어나면 길어질수 있는 최대 길이만큼만 반환)
  - `str.replace(시작 idx, 길이, 문자열)`: 시작 idx부터 길이만큼을 문자열로 대체.
  - `swap(str1,str2)`: str1과 str2를 서로 스왑
  - `str.(찾을 문자열,시작 idx)` : 시작 idx(없으면 0부터)에서 문자열을 찾아 시작 idx를 반환한다. 없으면 -1 반환
  - `str[idx]` `str.at(idx)` : 해당 idx의 문자를 반환한다.
  - `str.front()` `str.back()` : 문자열의 시작과 끝
  - `string::iterator iter` : 문자열의 이터레이터
    - `str1.begin()` : 시작
    - `str1.end()` : 종료
    - `*iter` : 해당 문자를 참조
  - `str1.compare(시작 idx, 길이, str2)` : 문자열을 비교
    1. `str1 == str2` : 0 반환
    2. `str1 > str2` : (비교는 사전순) -1 반환
    3. `str1 < str2` : (비교는 사전순) 1 반환

[위로 가기](#목차)


#### String 클래스(생성과 출력, 문자열 연결, push_back, pop_back)

```c++
#include<iostream>
#include<string>
using namespace std;

int main() {
    string str1 = "BlockDMask";
    string str2("BlogBlogBlogBlog");
    string str3(str1);

    //push_back, pop_back
    str1.push_back('1');
    cout << str1 << endl; // BlockDMask1
    str1.push_back('2');
    cout << str1 << endl; // BlockDMask12
    str1.pop_back();
    cout  << str1 << endl; // BlockDMask1
    str1.pop_back();
    cout << str1 << endl; // BlockDMask

    //operator+ stirng 덧셈.
    str1 += str2;
    cout << str1 << endl; // BlockDMaskBlogBlogBlogBlog
    return 0;
}
// 출처: https://blockdmask.tistory.com/338 [개발자 지망생]
```

[위로 가기](#목차)


#### String 클래스 (size, capacity, length, clear, shrink_to_fit)

```c++
#include<iostream>
#include<string>
using namespace std;

int main() {
    string str2 = "BlogBlogBlogBlog";

    cout << str2.size() << endl; // string 객체 길이
    cout << str2.length() << endl; // string 객체 길이

    str2.resize(4); // string을 n만큼의 크기로 변환
    /*
      기존 string 길이 > n : 추가 문자 a
      기존 string 길이 < n : 남은 스트링을 버린다.
    */  
    str2.shrink_to_fit(); // string 길이에 비해 낭비되는 메모리를 줄이는 함수
    str2.clear(); // string을 지우는 함수
    return 0;
}
// 출처: https://blockdmask.tistory.com/338 [개발자 지망생]
```

[위로 가기](#목차)


#### String 클래스 (substr, replace, swap)

```c++
#include<iostream>
#include<string>
using namespace std;

int main() {
   string str1 = "BlockDMask";
   string str2 = "BlogBlogBlogBlog";

   //string substr example.
   cout << str1.substr(5) << endl; // DMask
   cout << str1.substr(5,1) << endl; // D

   //string replace example.
   cout << str1.replace(5, 2, str2) << endl; // BlockBlogBlogBlogBlogask

   //string swap example.
   string str3 = "C++ example";
   swap(str2, str3)
   /*
      str2 = "C++ example";
      str3 = "BlogBlogBlogBlog"
   */
   return 0;
}
// 출처: https://blockdmask.tistory.com/338 [개발자 지망생]
```

[위로 가기](#목차)

#### String 클래스 (find, operaotr[], at, front, back)

```c++
#include<iostream>
#include<string>
using namespace std;

int main() {
  string str1 = "BlockDMask";
  string str2 = "BlogBlogBlogBlog";

  //find
  cout << str1.find("DM") << endl; // 5
  cout << str2.find("Blog") << endl; // 0
  cout << str2.find("Blog", 5) << endl; // 8

  //operator[], at
  cout << str1[0] << str1.at(0) << endl; // B
  cout << str1[3] << str1.at(3) << endl; // o
  cout << str1[str1.size() - 1] << str1.at(str1.size() - 1)  << endl; // k

  //front, back
  cout << str1[0] << str1.at(0) << str1.front() << endl;
  cout << str1[str1.size() - 1] << str1.at(str1.size() - 1) << str1.back() << endl;
  return 0;
}
// 출처: https://blockdmask.tistory.com/338 [개발자 지망생]
```

[위로 가기](#목차)

#### String 클래스 (begin, end, compare)

```c++
#include<iostream>
#include<string>
using namespace std;

int main() {
  string str1 = "BlockDMask";
  string str2 = "BlogBlogBlogBloc";

  //begin, end
  string::iterator iter;
  for (iter = str1.begin(); iter != str1.end(); ++iter) {
      cout << *iter << " ";
  } // B l o c k D M a s k

  //compare
  cout << str1.compare("BlockDMask") << endl; // 0
  cout << str1.compare(str2) << endl; // -1
  cout << str2.compare(str1) << endl; // 1
  return 0;
}
// 출처: https://blockdmask.tistory.com/338 [개발자 지망생]
```

[위로 가기](#목차)

### Vector
  - 자동으로 메모리가 할당되는 배열.(배열보다 많이 사용)
  - `벡터 선언`
    - `vector<int> v` : 비어있는 벡터 선언
    - `vector<int> v(5)` : 크기가 5이고, 0으로 초기화된 벡터 생성
    - `vector<int> v(5,2)` : 크기가 5이고, 2로 초기화된 벡터 생성
    - `vector<int> v(v1)` : v1을 복사한 v 생성
    - `벡터는 연산자로 비교 가능`
  - `vector.assign(원소 개수,value)` : 개수만큼 value 할당.
  - `vector.at(idx)` `vector[idx]` : idx번째 원소를 참조
  - `vector.front()` `vector.back()` : 처음과 마지막 원소
  - `vector.clear()` : 모든 원소 제거
  - `vector.push_back(value)` : 맨 뒤에 value 추가
  - `vector.pop_back()` : 맨 뒤의 원소 제거
  - `vector<int>::iterator iter`
    - `vector.begin()` `vector.end()` : 시작과 끝
    - `vector.rbegin()` `vector.rend()`: 거꾸로해서 시작과 끝
  - `vector.reserve(n)` : n개의 원소를 저장할 위치 예약
  - `vector.resize(n,value)` : 크기를 n으로 변경(더 커질 경우 value으로 초기화)
  - `vector.size()` : 벡터의 크기 반환
  - `v2.swap(v1)` : v1과 v2의 원소를 바꾼다.
  - `vector.insert(idx, cnt, value)` : idx에 cnt만큼 value 삽입(뒤의 원소들은 밀린다.)
  - `vector.erase(iter)` : iter가 가리키는 원소 제거.
   - 특정 위치를 제거하기 위해선 `iter += (idx-1)` 을 이용해 iter를 입력한다.
   - `vector.erase(start,end)` : 범위만큼 제거
  - `vector.empty()`
    - 벡터가 비어있는 경우 `true`
    - 벡터가 비어있지 않은 경우 `false`

[위로 가기](#목차)
