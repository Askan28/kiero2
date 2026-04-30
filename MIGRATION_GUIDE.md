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

```C++
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

### No more kiero::RenderType::Auto

Due to the presence of games where several types of renderers are supported, in order to implement this the way we would like, we need to develop a deep analysis system.

So we decided to abandon this feature.

You now have to specify the render type explicitly.

You can also use trick from the old kiero:

```C++
union {
  kiero::D3D9Output d3d9;
  kiero::D3D10Output d3d10;
  kiero::D3D11Output d3d11;
  kiero::D3D12Output d3d12;
  kiero::OpenGLOutput opengl;
  kiero::VulkanOutput vulkan;
} output;

if (GetModuleHandleA("d3d12.dll")) {
  kiero::locate<kiero::Implementation_D3D12>(nullptr, &output.d3d12);
} else if (GetModuleHandleA("d3d11.dll")) {
  kiero::locate<kiero::Implementation_D3D11>(nullptr, &output.d3d11);
} else if (GetModuleHandleA("d3d10.dll")) {
  kiero::locate<kiero::Implementation_D3D10>(nullptr, &output.d3d10);
} else if (GetModuleHandleA("d3d9.dll")) {
  kiero::locate<kiero::Implementation_D3D9>(nullptr, &output.d3d9);
} else if (GetModuleHandleA("opengl32.dll")) {
  kiero::locate<kiero::Implementation_OpenGL>(nullptr, &output.opengl);
} else if (GetModuleHandleA("vulkan-1.dll")) {
  kiero::locate<kiero::Implementation_Vulkan>(nullptr, &output.vulkan);
}
```