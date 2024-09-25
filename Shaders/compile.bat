echo "Script executed from: " %VULKAN_SDK%
"%VULKAN_SDK%\Bin\glslc.exe" shader.vert -o SpirV/vert.spv
"%VULKAN_SDK%\Bin\glslc.exe" shader.frag -o SpirV/frag.spv
