/*
Copyright 2014 Moritz Kaufmann, Manuel Then, Tobias Muehlbauer, Andrey Gubichev

Licensed under the Apache License, Version 2.0 (the "License");
you may not use this file except in compliance with the License.
You may obtain a copy of the License at

  http://www.apache.org/licenses/LICENSE-2.0

Unless required by applicable law or agreed to in writing, software
distributed under the License is distributed on an "AS IS" BASIS,
WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
See the License for the specific language governing permissions and
limitations under the License.
*/

#pragma once

#include <cstdio>

namespace awfy {
   namespace memoryhooks {
      struct CurrentThread {
         static __thread void (*report_fn) (size_t);
      };

      /* Prototypes for our hooks.  */
      inline void malloc_hook (size_t size) {
         /* Call recursively */
         if(CurrentThread::report_fn!=0) {
            (*CurrentThread::report_fn)(size);
         }
      }
   }
}