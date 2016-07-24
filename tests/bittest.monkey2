enum Bits
One=1
Ugly=$80000000
end

function Main()
print "hello"
print int(Bits.One)
print int(Bits.Ugly)
local a:=Bits.One
local b:=(a&Bits.Ugly)<>null
print b
End

