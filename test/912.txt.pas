program sssp;
var m,c,i,j:longint;
    a,b,n,s,r:word;
    t:array[1..1000]of word;
    l:array[1..1000,1..1000]of word;
    g,z:array[1..1000]of longint;
    k:array[1..1000]of boolean;
    q:array[1..1000]of word;
    v:array[1..1000,1..1000]of longint;
begin
  readln(n,m,s);
  for i:=1 to m do
    begin
      readln(a,b,c);
      if v[a,b]=0 then
        begin
          v[a,b]:=c;
          inc(t[a]);
          l[a,t[a]]:=b;
        end
      else
        if v[a,b]>c then
          v[a,b]:=c;
    end;
  for i:=1 to n do
    begin
      a:=1;
      r:=0;
      for j:=1 to n do
        g[j]:=maxlongint;
      g[i]:=0;
      q[1]:=i;
      k[i]:=true;
      repeat
        b:=q[a];
        dec(a);
        for j:=1 to t[b] do
          begin
            m:=v[b,l[b,j]]+g[b];
            inc(r);
            if m<g[l[b,j]] then
              begin
                if l[b,j]=i then
                  begin
                    writeln(-1);
                    exit;
                  end;
                g[l[b,j]]:=m;
                if k[l[b,j]]=false then
                  begin
                    k[l[b,j]]:=true;
                    c:=a;
                    inc(a);
                    if(c>0)and(g[l[b,j]]>g[q[c]])then
                      begin
                        q[a]:=q[c];
                        q[c]:=l[b,j];
                      end
                    else
                      q[a]:=l[b,j];
                  end;
              end;
            if(r>5000)and(i<>s)then
              break;
          end;
        k[b]:=false;
      until a=0;
      if i=s then
        for j:=1 to n do
          z[j]:=g[j];
    end;
  for i:=1 to n do
    if z[i]=maxlongint then
      writeln('NoPath')
    else
      writeln(z[i]);
end.
