#Import "<std>"
Using std..
Function Main()
	Print "delete test"
	Local list:=New List<String>()
	list.AddLast("one")
	list.AddLast("two")
	list.AddLast("three")
	For Local i:=Eachin list
		If i="two" Then list.Remove(i)
		Print i
	Next
End
