var
	x,y,i,j,k,n,max,pa:longint;
	a,b,f,s:array[1..50000] of longint;
        c:array[0..49999] of longint;
procedure wan;
begin
		writeln('-1');
	 halt;
end;
begin
	readln(n);
	for i:=1 to n do
	  begin
		readln(x,y); a[i]:=x; b[i]:=y;
	  end;
	for i:=1 to n do
	if (a[a[i]]<>i) and (a[b[i]]<>i) and (b[a[i]]<>i) and (b[b[i]]<>i)
	then wan;
	f[1]:=1; i:=1; k:=a[1]; j:=1;   s[1]:=1;
	while i<n do begin
		inc(i); pa:=0;
		f[i]:=k;
                s[k]:=1;
		if s[a[k]]=0 then begin k:=a[k]; pa:=1; end
		else if s[b[k]]=0 then begin k:=b[k]; pa:=1; end;
		if (pa=0) and (n<>i) then wan;
	end;
        fillchar(c,sizeof(c),0);
        max:=-1;
        for i:=1 to n do inc(c[(f[i]-i+n) mod n]);
        for i:=0 to n-1 do if c[i]>max then max:=c[i];
        fillchar(c,sizeof(c),0);
        for i:=1 to n do
        inc(c[(f[n-i+1]-i+n) mod n]);
        for i:=0 to n-1 do if c[i]>max then max:=c[i];
        write(n-max);
end.
	

