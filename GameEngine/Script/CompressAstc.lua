-- https://stackoverflow.com/questions/9102126/lua-return-directory-path-from-path
local function get_base_path(str, sep)
    sep = sep or'/'
    return str:match("(.*"..sep..")")
end

argc = #arg

if argc ~= 2 then
    print("invalid compress file name or block size...")
    os.exit()
end

src = arg[1]
save_path = get_base_path(src, "\\")
block_size = arg[2]

-- https://arm-software.github.io/opengl-es-sdk-for-android/astc_textures.html
block_sizes = {
    "4x4",
    "5x4",
    "5x5",
    "6x5",
    "6x6",
    "8x5",
    "8x6",
    "8x8",
    "10x5",
    "10x6",
    "10x8",
    "10x10",
    "12x10",
    "12x12"
}
