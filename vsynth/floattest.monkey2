Function Main()
	Local value:=0.4
	Local dp:=2
	Local integral:=Int(value*(Pow(10,dp)))
	Print integral
	
	Local word:=1024
	Local pitchbend:Double=1.0+(word-8192)/8192.0
	
	Print "pitchbend="+pitchbend
End
