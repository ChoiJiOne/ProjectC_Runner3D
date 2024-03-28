-- https://stackoverflow.com/questions/9102126/lua-return-directory-path-from-path
local function get_base_path(str, sep)
    sep = sep or'/'
    return str:match("(.*"..sep..")")
end

-- https://gist.github.com/tingliang0/d9672e0656130eabbd2f
local function get_file_name_with_extension(file)
    return file:match( "([^\\]+)$" )
end

-- https://gist.github.com/tingliang0/d9672e0656130eabbd2f
local function get_file_name(file)
    name_with_extension = get_file_name_with_extension(file)
    return name_with_extension:match("([^/\\]+)%.%w+$")
end

local function get_file_extension(file)
    name_with_extension = get_file_name_with_extension(file)
    return name_with_extension:match("%.(%w+)$")
end

argc = #arg

if argc ~= 2 then
    print("invalid compress file name or block size...")
    os.exit()
end

src = arg[1]
save_path = get_base_path(src, "\\")
block_size = arg[2]

print(get_file_name(src))
print(get_file_extension(src))

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
