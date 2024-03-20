echo "Testing bad path texture"
./cub3D maps/broken/badpathtexture.cub
echo "Testing empty line in map"
./cub3D maps/broken/emptylinemap.cub
echo "Testing missing texture"
./cub3D maps/broken/missingtexture.cub
echo "Testing bad rgb value"
./cub3D maps/broken/badrgbvalue.cub
echo "Testing empty texture path"
./cub3D maps/broken/emptytexturepath.cub
echo "Testing negative rgb value"
./cub3D maps/broken/negativergbvalue.cub
echo "Testing bad rgb value with space"
./cub3D maps/broken/badrgbvaluespace.cub
echo "Testing high rgb value"
./cub3D maps/broken/highrgbvalue.cub
echo "Testing negative rgb value with space"
./cub3D maps/broken/negativergbvaluespace.cub
echo "Testing directory for texture path"
./cub3D maps/broken/directorytexturepath.cub
echo "Testing high rgb value with space"
./cub3D maps/broken/highrgbvaluespace.cub
echo "Testing not closed map"
./cub3D maps/broken/notclosed.cub
echo "Testing 2 floor entries"
./cub3D maps/broken/doublefloor.cub
echo "Testing missing color entry"
./cub3D maps/broken/missingcolor.cub
echo "Testing just a period for texture path"
./cub3D maps/broken/periodtexturepath.cub
echo "Testing 2 starting positions"
./cub3D maps/broken/doublestart.cub
echo "Testing .cub without a map"
./cub3D maps/broken/missingmap.cub
echo "Testing wrong extension"
./cub3D maps/broken/wrongextension.cubw
echo "Testing 2 texture definitions"
./cub3D maps/broken/doubletexture.cub
echo "Testing missing rgb value"
./cub3D maps/broken/missingrgbvalue.cub
