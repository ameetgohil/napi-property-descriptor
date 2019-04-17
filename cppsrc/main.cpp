#include <napi.h>
#include <iostream>

int testValue = 3;

Napi::Value Get(const Napi::CallbackInfo& info) {
    return Napi::Number::New(info.Env(), testValue);
}

void Set(const Napi::CallbackInfo& info) {
    testValue = info[0].As<Napi::Number>();
    std::cout << "c++ source: " << testValue << "\n";
}
Napi::Object Init(Napi::Env env, Napi::Object exports) {
    napi_status status;
    
    //Accessor
    Napi::PropertyDescriptor pd1 = Napi::PropertyDescriptor::Accessor(env,
							  exports,
							  "pd1",
							  Get,
							  Set);

 
    exports.DefineProperties({pd1});

    return exports;
    
}

NODE_API_MODULE(NODE_GYP_MODULE_NAME, Init)
