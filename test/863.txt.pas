Program vijos1143;

  Const
    maxn=30;

  Type
    datatype=longint;

  Var
    a:array [1..maxn,1..maxn] of datatype;
    f:array [0..(maxn+maxn),0..maxn,0..maxn,0..maxn] of datatype;
    n:datatype;

  Procedure init;
  Var i,j:datatype;
  Begin
    Readln(n);
    For i:=1 to n do
      For j:=1 to n do
        Read(a[i,j]);
    Fillchar(f,sizeof(f),0);
  End;

  Function max(p,q:datatype):datatype;
  Begin
    If p>q Then
      Exit(p);
    Exit(q);
  End;

  Function sum(i,j,k,l:datatype):datatype;
  Begin
    If (k=j) and (j=l) Then
      Exit(a[k,i-k]);
    If k=j Then
      Exit(a[k,i-k]+a[l,i-l]);
    If j=l Then
      Exit(a[k,i-k]+a[j,i-j]);
    If k=l Then
      Exit(a[k,i-k]+a[j,i-j]);
    Exit(a[k,i-k]+a[j,i-j]+a[l,i-l]);
  End;

  Procedure main;
  Var i,j,k,l,m,x,y,z:datatype;
  Begin
    For i:=2 to n+n do
    Begin
      If i>=n Then m:=n Else m:=i;
      For j:=1 to m do
        For k:=1 to m do
          For l:=1 to m do
          Begin
            For x:=0 to 1 do
              For y:=0 to 1 do
                For z:=0 to 1 do
                  f[i,j,k,l]:=max(f[i,j,k,l],f[i-1,j-x,k-y,l-z]);
            f[i,j,k,l]:=f[i,j,k,l]+sum(i,j,k,l);
          End;
    End;
    Writeln(f[n+n,n,n,n]);
  End;

  Begin
    init;
    main;
  End.
