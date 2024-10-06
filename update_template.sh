rm contest_template/.blank/main.cpp
cp template.cpp contest_template/.blank/main.cpp

for s in a b c d e f g h i j k l; do
	rm "contest_template/$s/main.cpp"
	cp template.cpp "contest_template/$s/main.cpp"
done

