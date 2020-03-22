#include "misc.h"

#include "api/adsi/IADs.h"

namespace myAddon {

Napi::Value hello(const Napi::CallbackInfo &info) {
  Napi::Env env = info.Env();
  return Napi::String::New(env, "Coucou JL!!!");
}

Napi::Object Init(Napi::Env env, Napi::Object exports) {
  initFlags();

  exports.Set(Napi::String::New(env, "hello"), Napi::Function::New(env, hello));

  exports.Set(Napi::String::New(env, "EnumerateSecurityPackages"),
              Napi::Function::New(env, e_EnumerateSecurityPackages));

  exports.Set(Napi::String::New(env, "QuerySecurityPackageInfo"),
              Napi::Function::New(env, e_QuerySecurityPackageInfo));

  exports.Set(Napi::String::New(env, "AcquireCredentialsHandle"),
              Napi::Function::New(env, e_AcquireCredentialsHandle));

  exports.Set(Napi::String::New(env, "QueryCredentialsAttributes"),
              Napi::Function::New(env, e_QueryCredentialsAttributes));

  exports.Set(Napi::String::New(env, "QueryContextAttributes"),
              Napi::Function::New(env, e_QueryContextAttributes));

  exports.Set(Napi::String::New(env, "QuerySecurityContextToken"),
              Napi::Function::New(env, e_QuerySecurityContextToken));

  exports.Set(Napi::String::New(env, "OpenThreadToken"),
              Napi::Function::New(env, e_OpenThreadToken));

  exports.Set(Napi::String::New(env, "OpenProcessToken"),
              Napi::Function::New(env, e_OpenProcessToken));

  exports.Set(Napi::String::New(env, "GetTokenInformation"),
              Napi::Function::New(env, e_GetTokenInformation));

  exports.Set(Napi::String::New(env, "CloseHandle"),
              Napi::Function::New(env, e_CloseHandle));

  exports.Set(Napi::String::New(env, "FreeCredentialsHandle"),
              Napi::Function::New(env, e_FreeCredentialsHandle));

  exports.Set(Napi::String::New(env, "InitializeSecurityContext"),
              Napi::Function::New(env, e_InitializeSecurityContext));

  exports.Set(Napi::String::New(env, "AcceptSecurityContext"),
              Napi::Function::New(env, e_AcceptSecurityContext));

  exports.Set(Napi::String::New(env, "DeleteSecurityContext"),
              Napi::Function::New(env, e_DeleteSecurityContext));

  exports.Set(Napi::String::New(env, "ImpersonateSecurityContext"),
              Napi::Function::New(env, e_ImpersonateSecurityContext));

  exports.Set(Napi::String::New(env, "RevertSecurityContext"),
              Napi::Function::New(env, e_RevertSecurityContext));

  exports.Set(Napi::String::New(env, "GetUserName"),
              Napi::Function::New(env, e_GetUserName));

  exports.Set(Napi::String::New(env, "GetUserNameEx"),
              Napi::Function::New(env, e_GetUserNameEx));

  exports.Set("LookupAccountName",
              Napi::Function::New(env, e_LookupAccountName));

  // ADSI
  exports.Set("CoInitialize", Napi::Function::New(env, e_CoInitialize));
  exports.Set("CoUninitialize", Napi::Function::New(env, e_CoUninitialize));
  exports.Set("ADsGestObject", Napi::Function::New(env, e_ADsGestObject));
  exports.Set("ADsOpenObject", Napi::Function::New(env, e_ADsOpenObject));
  exports.Set("ADsBuildEnumerator", Napi::Function::New(env, e_ADsBuildEnumerator));

  E_IADs::Init(env, exports);


  return exports;
}

NODE_API_MODULE(NODE_GYP_MODULE_NAME, Init)

}  // namespace myAddon
