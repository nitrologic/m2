
source common.sh

echo ""
echo "***** Rebuilding modules *****"
echo ""

$mx2cc makemods -target=pi -config=release
#$mx2cc makemods -clean -target=pi -config=release

#$mx2cc makemods -clean -target=pi -config=debug
