## ft_printf
#### by fde-capu

### Forty-Two PrintF
is a project to emulate the infamous <stdio.h printf>.
It is not designed to have all functionalities, but is does some neat things.

Thanks for checking it out. Just don't freak out.

#### Specifications:
- The prototype: `int ft_printf(const char *, ...);`
- Recode the libc’s `printf` function.
- It manages the following conversions: `"cspdiuxX%"`
- It manages any combination of the flags: `"-0.*"` and minimum field width with all conversions.
- Library created with `ar` (libtool is forbidden).

---

*this project is part of the 42 São Paulo cursus*

---

Copyright 2020 fde-capu

Licensed under the Apache License, Version 2.0 (the "License");
you may not use this file except in compliance with the License.
You may obtain a copy of the License at

    http://www.apache.org/licenses/LICENSE-2.0

Unless required by applicable law or agreed to in writing, software
distributed under the License is distributed on an "AS IS" BASIS,
WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
See the License for the specific language governing permissions and
limitations under the License.
