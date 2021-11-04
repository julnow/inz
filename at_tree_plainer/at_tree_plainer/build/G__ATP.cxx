// Do NOT change. Changes will be lost next time file is generated

#define R__DICTIONARY_FILENAME G__ATP
#define R__NO_DEPRECATION

/*******************************************************************/
#include <stddef.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <assert.h>
#define G__DICTIONARY
#include "RConfig.h"
#include "TClass.h"
#include "TDictAttributeMap.h"
#include "TInterpreter.h"
#include "TROOT.h"
#include "TBuffer.h"
#include "TMemberInspector.h"
#include "TInterpreter.h"
#include "TVirtualMutex.h"
#include "TError.h"

#ifndef G__ROOT
#define G__ROOT
#endif

#include "RtypesImp.h"
#include "TIsAProxy.h"
#include "TFileMergeInfo.h"
#include <algorithm>
#include "TCollectionProxyInfo.h"
/*******************************************************************/

#include "TDataMember.h"

// Header files passed as explicit arguments
#include "ATreePlainer.hpp"

// Header files passed via #pragma extra_include

// The generated code does not explicitly qualify STL entities
namespace std {} using namespace std;

namespace ROOT {
   static TClass *ATreePlainer_Dictionary();
   static void ATreePlainer_TClassManip(TClass*);
   static void *new_ATreePlainer(void *p = 0);
   static void *newArray_ATreePlainer(Long_t size, void *p);
   static void delete_ATreePlainer(void *p);
   static void deleteArray_ATreePlainer(void *p);
   static void destruct_ATreePlainer(void *p);

   // Function generating the singleton type initializer
   static TGenericClassInfo *GenerateInitInstanceLocal(const ::ATreePlainer*)
   {
      ::ATreePlainer *ptr = 0;
      static ::TVirtualIsAProxy* isa_proxy = new ::TIsAProxy(typeid(::ATreePlainer));
      static ::ROOT::TGenericClassInfo 
         instance("ATreePlainer", "ATreePlainer.hpp", 8,
                  typeid(::ATreePlainer), ::ROOT::Internal::DefineBehavior(ptr, ptr),
                  &ATreePlainer_Dictionary, isa_proxy, 4,
                  sizeof(::ATreePlainer) );
      instance.SetNew(&new_ATreePlainer);
      instance.SetNewArray(&newArray_ATreePlainer);
      instance.SetDelete(&delete_ATreePlainer);
      instance.SetDeleteArray(&deleteArray_ATreePlainer);
      instance.SetDestructor(&destruct_ATreePlainer);
      return &instance;
   }
   TGenericClassInfo *GenerateInitInstance(const ::ATreePlainer*)
   {
      return GenerateInitInstanceLocal((::ATreePlainer*)0);
   }
   // Static variable to force the class initialization
   static ::ROOT::TGenericClassInfo *_R__UNIQUE_DICT_(Init) = GenerateInitInstanceLocal((const ::ATreePlainer*)0x0); R__UseDummy(_R__UNIQUE_DICT_(Init));

   // Dictionary for non-ClassDef classes
   static TClass *ATreePlainer_Dictionary() {
      TClass* theClass =::ROOT::GenerateInitInstanceLocal((const ::ATreePlainer*)0x0)->GetClass();
      ATreePlainer_TClassManip(theClass);
   return theClass;
   }

   static void ATreePlainer_TClassManip(TClass* ){
   }

} // end of namespace ROOT

namespace ROOT {
   // Wrappers around operator new
   static void *new_ATreePlainer(void *p) {
      return  p ? new(p) ::ATreePlainer : new ::ATreePlainer;
   }
   static void *newArray_ATreePlainer(Long_t nElements, void *p) {
      return p ? new(p) ::ATreePlainer[nElements] : new ::ATreePlainer[nElements];
   }
   // Wrapper around operator delete
   static void delete_ATreePlainer(void *p) {
      delete ((::ATreePlainer*)p);
   }
   static void deleteArray_ATreePlainer(void *p) {
      delete [] ((::ATreePlainer*)p);
   }
   static void destruct_ATreePlainer(void *p) {
      typedef ::ATreePlainer current_t;
      ((current_t*)p)->~current_t();
   }
} // end of namespace ROOT for class ::ATreePlainer

namespace {
  void TriggerDictionaryInitialization_libATP_Impl() {
    static const char* headers[] = {
"ATreePlainer.hpp",
0
    };
    static const char* includePaths[] = {
"/Users/julnow/gsi/inz/at_tree_plainer/at_tree_plainer",
"/opt/homebrew/Cellar/root/6.24.04_1/include/root",
"/Users/julnow/cbmdir/AnalysisTree/install/include",
"/opt/homebrew/Cellar/root/6.24.04_1/include/root",
"/Users/julnow/gsi/inz/at_tree_plainer/at_tree_plainer/build/",
0
    };
    static const char* fwdDeclCode = R"DICTFWDDCLS(
#line 1 "libATP dictionary forward declarations' payload"
#pragma clang diagnostic ignored "-Wkeyword-compat"
#pragma clang diagnostic ignored "-Wignored-attributes"
#pragma clang diagnostic ignored "-Wreturn-type-c-linkage"
extern int __Cling_AutoLoading_Map;
class __attribute__((annotate("$clingAutoload$ATreePlainer.hpp")))  ATreePlainer;
)DICTFWDDCLS";
    static const char* payloadCode = R"DICTPAYLOAD(
#line 1 "libATP dictionary payload"

#ifndef DO_TPCCATRACKER_EFF_PERFORMANCE
  #define DO_TPCCATRACKER_EFF_PERFORMANCE 1
#endif

#define _BACKWARD_BACKWARD_WARNING_H
// Inline headers
#include "ATreePlainer.hpp"

#undef  _BACKWARD_BACKWARD_WARNING_H
)DICTPAYLOAD";
    static const char* classesHeaders[] = {
"ATreePlainer", payloadCode, "@",
nullptr
};
    static bool isInitialized = false;
    if (!isInitialized) {
      TROOT::RegisterModule("libATP",
        headers, includePaths, payloadCode, fwdDeclCode,
        TriggerDictionaryInitialization_libATP_Impl, {}, classesHeaders, /*hasCxxModule*/false);
      isInitialized = true;
    }
  }
  static struct DictInit {
    DictInit() {
      TriggerDictionaryInitialization_libATP_Impl();
    }
  } __TheDictionaryInitializer;
}
void TriggerDictionaryInitialization_libATP() {
  TriggerDictionaryInitialization_libATP_Impl();
}
