### C++ 헤더파일 (bits/stdc++.h)

```c++
#include <bits/stdc++.h>
```

### bits/stdc++.h란 무엇인가
- 자주 사용하는 표준 라이브러리들을 한번에 컴파일하도록
- 백준, 코드포스 같은 온라인 저지에서 bits/stdc++.h 헤더 지원

### 장점
- "iostream" "vector" 등의 헤더파일을 반복적으로 include 하지 않아 시간 절약
- 특정 함수가 어떤 헤더에 있는지 찾을 필요 없이 설정

### 단점
- GNU C++ 표준 라이브러리 헤더 파일이 아님 -> gcc 이외의 컴파일러에서는 에러 => 컴파일러 종속적
- 필요 없는 라이브러리도 컴파일 함

### 사용 법 (Visual Studio 기준)
- stdc++.h 파일 다운로드 (https://gist.github.com/Einstrasse/ac0fe7d7450621a39364ed3b05cacd11)
- 다음 경로(vs 버전에 따라 경로가 다름)에 `C:\Program Files (x86)\Microsoft Visual Studio\2019\Community\VC\Tools\MSVC\14.29.30037\include`
- bits 폴더 생성
- stdc++.h 파일 옮기기
- VS 업데이트 할 경우 수동으로 파일을 옮겨야 한다.

<details>
<summary>stdc++.h 파일 내용</summary>   
<div markdown="1">
    
  ```c++
  // C++ includes used for precompiling -*- C++ -*-

// Copyright (C) 2003-2013 Free Software Foundation, Inc.
//
// This file is part of the GNU ISO C++ Library.  This library is free
// software; you can redistribute it and/or modify it under the
// terms of the GNU General Public License as published by the
// Free Software Foundation; either version 3, or (at your option)
// any later version.

// This library is distributed in the hope that it will be useful,
// but WITHOUT ANY WARRANTY; without even the implied warranty of
// MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
// GNU General Public License for more details.

// Under Section 7 of GPL version 3, you are granted additional
// permissions described in the GCC Runtime Library Exception, version
// 3.1, as published by the Free Software Foundation.

// You should have received a copy of the GNU General Public License and
// a copy of the GCC Runtime Library Exception along with this program;
// see the files COPYING3 and COPYING.RUNTIME respectively.  If not, see
// <http://www.gnu.org/licenses/>.

/** @file stdc++.h
 *  This is an implementation file for a precompiled header.
 */

// 17.4.1.2 Headers

// C
#ifndef _GLIBCXX_NO_ASSERT
#include <cassert>
#endif
#include <cctype>
#include <cerrno>
#include <cfloat>
#include <ciso646>
#include <climits>
#include <clocale>
#include <cmath>
#include <csetjmp>
#include <csignal>
#include <cstdarg>
#include <cstddef>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <ctime>

#if __cplusplus >= 201103L
#include <ccomplex>
#include <cfenv>
#include <cinttypes>
#include <cstdalign>
#include <cstdbool>
#include <cstdint>
#include <ctgmath>
#include <cwchar>
#include <cwctype>
#endif

// C++
#include <algorithm>
#include <bitset>
#include <complex>
#include <deque>
#include <exception>
#include <fstream>
#include <functional>
#include <iomanip>
#include <ios>
#include <iosfwd>
#include <iostream>
#include <istream>
#include <iterator>
#include <limits>
#include <list>
#include <locale>
#include <map>
#include <memory>
#include <new>
#include <numeric>
#include <ostream>
#include <queue>
#include <set>
#include <sstream>
#include <stack>
#include <stdexcept>
#include <streambuf>
#include <string>
#include <typeinfo>
#include <utility>
#include <valarray>
#include <vector>

#if __cplusplus >= 201103L
#include <array>
#include <atomic>
#include <chrono>
#include <condition_variable>
#include <forward_list>
#include <future>
#include <initializer_list>
#include <mutex>
#include <random>
#include <ratio>
#include <regex>
#include <scoped_allocator>
#include <system_error>
#include <thread>
#include <tuple>
#include <typeindex>
#include <type_traits>
#include <unordered_map>
#include <unordered_set>
#endif
  ```
    
</div>  
    
</details>
