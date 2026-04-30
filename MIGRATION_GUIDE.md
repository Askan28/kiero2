## Introduction

After a long time, I find that kiero had too much responsibility for a library whose only real job is to tell you *where* a methods located. So I decided to create kiero v2, which focuses solely on the core purpose of the library: locating methods.


## Migrating from v1
```C++
// v1
if (kiero::init(kiero::RenderType::D3D9) != kiero::Status::Success) {
    return;
}

kiero::bind(42, (void**)&oEndScene, hkEndScene);
kiero::shutdown();
```

Same code on v2:

```
// v2
kiero::D3D9Output output;
auto error = kiero::locate<kiero::Implementation_D3D9>(nullptr, &output);
if (error != kiero::Error_Nil) {
    return;
}

auto oEndScene = output.device_methods[42];

// hook with your favorite hook library
MH_CreateHook(oEndScene, hkEndScene, nullptr);
MH_EnableHook(oEndScene);
```