open ReactNative;

include Theme;
let styles =
  StyleSheet.create(
    Style.{
      "container": style(~flex=1., ~backgroundColor=Colors.primaryDark, ()),
      "button":
        style(
          ~width=(dimensions##width /. 2.)->dp,
          ~height=45.->dp,
          ~justifyContent=`center,
          ~alignItems=`center,
          ~borderBottomWidth=2.,
          (),
        ),
      "buttonContainer": style(~flex=1., ()),
      "buttonText":
        style(
          ~color=Colors.primaryText,
          ~textAlign=`center,
          ~fontFamily=Typography.primary,
          (),
        ),
      "tabContainer": style(~flexDirection=`row, ()),
      "indexSelected":
        style(
          ~backgroundColor=Colors.primary2,
          ~borderBottomColor=Colors.highlight,
          (),
        ),
      "indexNotSelected":
        style(
          ~backgroundColor=Colors.primary,
          ~borderBottomColor=Colors.primary,
          (),
        ),
    },
  );