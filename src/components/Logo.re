// open ReactNative;
open ReactNative;
let styles =
  StyleSheet.create(
    Style.{
      "logoContainer":
        style(
          ~marginTop=70.->dp,
          ~justifyContent=`center,
          ~alignItems=`center,
          (),
        ),
      "logo": style(~height=50.->dp, ~width=200.->dp, ()),
    },
  );
  [@react.component]
  let make = () => {
    <View style=styles##logoContainer>
      <Image style=styles##logo resizeMode=`contain source=Theme.logo />
    </View>;
  };