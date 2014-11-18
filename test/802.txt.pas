(*Status: Finish Coding*)
{$m 1000000}
Const
	MaxE=524288;
	MaxN=20000;
	Infinity=10000000;

Type
	Thp=Record
	start,ending,mid,Min:Longint;
	end;
	Thp2=Record
	s,e,c:Longint;
	end;

Var
	T:Array[1..MaxE] of Thp;
	P:Array[1..MaxN] of thp2;
	F:Array[0..MaxE] of Longint;
	Temp,Tmp,Q,Ans,S,E,N,I,J,K:Longint;

Procedure Dfs(X,st,eg:Longint);
Var
	Mid:Longint;
Begin
	If st>eg then Exit;
	Mid:=(st+eg) div 2;
	T[X].start:=st;
	T[X].ending:=eg;
	T[X].Min:=Infinity;
	T[X].mid:=Mid;
	If st=eg then Exit;
	Dfs(2*X,st,Mid);
	Dfs(2*X+1,Mid+1,eg);
End;

Function Min(a,b:Longint):Longint;
Begin
	If a<b then Min:=a else Min:=b;
End;

Procedure Ind(X,d,data:Longint);
Begin
	If (T[x].start=0) or (T[x].ending=0) or (T[x].start>T[x].ending) then Exit;
	If Not( (T[X].start<=d) and (d<=T[X].ending) ) then Exit;
	If (T[X].start=T[X].ending) and (T[X].start=d) then
	Begin
		T[X].Min:=data;
		Exit;
	End;
	T[X].Min:=Min(T[X].Min,data);
	Ind(2*X,d,data);
	Ind(2*X+1,d,data);
End;

Procedure Find(X,ss,gg:Longint);
Var
	ii,tmp:Longint;
Begin
	If ss>gg then Exit;
	Tmp:=infinity;
	If (ss=T[X].start) and (gg=T[X].ending) then
	Begin
		Temp:=min(temp,T[X].min);
		Exit;
	End;
	if gg<=T[X].mid
		then
			begin
        Find(2*X,ss,gg);
      end
		else
      begin
        Find(2*X,ss,T[X].mid);
      end;
	if ss>T[X].mid
		then
      begin
			  Find(2*X+1,ss,gg);
      end
		else
      begin
			  Find(2*X+1,T[X].mid+1,gg);
      end;
End;

Procedure QuickSort(ss,gg:Longint);
Var
	I,J:Longint;
	Mid,tmp:Thp2;
Begin
	I:=ss; J:=gg;
  Mid:=P[(I+J) div 2];
	Repeat
		While (i<=j) and (P[i].e<Mid.e) do inc(i);
		While (i<=j) and (mid.e<p[j].e) do dec(j);
		if I<=j then
		Begin
			tmp:=P[i];
			P[i]:=P[j];
			P[j]:=tmp;
			Inc(I); Dec(J);
		End;
	Until i>j;
	If I<gg then QuickSort(I,gg);
	If ss<j then QuickSort(ss,J);
End;

Procedure Swap(var a,b:Longint);
Var
	tmp:Longint;
Begin
	tmp:=a; a:=b; b:=tmp;
End;

Begin

	Fillchar(T,sizeof(T),0);
	Dfs(1,1,131072);
	Read(N,S,E);
	For I:=1 to N do
	Begin
		Read(P[I].s,P[i].e,P[i].c);
		if P[i].s>P[i].e then Swap(P[i].s,P[i].e);
    Inc(P[i].s);
    Inc(P[i].e);
	End;
	QuickSort(1,N);
	//Writeln('Finish 1');
	{For I:=1 to N do
	Begin
		Writeln(P[i].S,' ',P[i].e,' ',P[i].c);
	End;}
  {Writeln('st');
	For I:=1 to N do
	Begin
		Writeln(P[i].s,' ',P[i].e,' ',P[i].c);
	End; }
  //Writeln('Finish');
  Inc(S);
  Inc(E);
	For I:=1 to MaxE do
	F[i]:=Infinity;
	F[0]:=0;
	For I:=0 to S-1 do
	F[I]:=0;
	For I:=1 to N do
	Begin
		K:=P[i].e;
		Q:=P[i].s;
		//Writeln('Finish 2');
		Tmp:=Infinity;
		if Q<=S then Tmp:=0;
		If Q>S then
    Begin
      temp:=infinity;
      Find(1,Q-1,K-1);
		  Tmp:=Min(Tmp,Temp);
      //Writeln('Search',Q-1,' ',K-1);
    End;
    //else Tmp:=Min(Tmp,Find(1,Q,k-1));
		//Writeln('Tmp ',i,' ',Tmp);
		F[k]:=Min(F[k],Tmp+P[i].c);
		//Writeln('F',' ',k,' ',' ',F[k]);
		If K<>0 then Ind(1,k,F[k]);
	End;
	Ans:=Infinity;
	For I:=E to MaxE do
	Ans:=Min(Ans,F[I]);
  If ans<>Infinity then Writeln(Ans) else writeln('-1');
	
End.
