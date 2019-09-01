open ReactNative;
include Theme;
let styles =
  StyleSheet.create(
    Style.{
      "headerStyle":
        style(
        ~backgroundColor=Colors.primary,
        ~borderBottomColor=Colors.primaryLight,
        ~borderBottomWidth=1.,
          (),
        ),
      "bottomButton":
        style(
          ~width=(dimensions##width /. 2.)->dp,
          ~height=45.->dp,
          ~alignItems=`center,
          ~justifyContent=`center,
          ~borderTopWidth=1.,
          (),
        ),
      "bottomButtonText":
        style(~color=Colors.highlight, ~fontFamily=Typography.primary, ()),
      "tabBottomContainer":
        style(
          ~flexDirection=`row,
          ~position=`absolute,
          ~width=dimensions##width->dp,
          ~borderTopWidth=1.,
          ~borderBottomWidth=1.,
          ~borderTopColor="rgba(255, 255, 255, .2)",
          ~borderBottomColor="rgba(255, 255, 255, .2)",
          ~left=0.->dp,
          ~bottom=(-1.)->dp,
          (),
        ),
      "listContainer": style(~paddingBottom=70.->dp, ()),
      "speakerContainer":
        style(
          ~flexDirection=`row,
          ~paddingHorizontal=15.->dp,
          ~paddingBottom=10.->dp,
          (),
        ),
      "logo":
        style(
          ~marginLeft=10.->dp,
          ~marginBottom=4.->dp,
          ~width=120.->dp,
          ~height=35.->dp,
          (),
        ),
      "container": style(~flex=1., ~backgroundColor=Colors.primaryLight, ()),
      "loading":
        style(
          ~backgroundColor=Colors.primaryLight,
          ~flex=1.,
          ~justifyContent=`center,
          ~alignItems=`center,
          (),
        ),
      "talk":
        style(
          ~backgroundColor=Colors.primary,
          ~borderRadius=10.,
          ~margin=15.->dp,
          ~marginBottom=0.->dp,
          ~paddingTop=15.->dp,
          ~paddingBottom=0.->dp,
          (),
        ),
      "timeContainer":
        style(
          ~paddingHorizontal=20.->dp,
          ~paddingVertical=15.->dp,
          ~borderBottomLeftRadius=15.,
          ~borderBottomRightRadius=15.,
          ~backgroundColor=Colors.primaryDark,
          // ~backgroundColor="#ddd",
          (),
        ),
      "talkTime":
        style(~color=Colors.primaryText, ~fontFamily=Typography.primary, ()),
      "infoContainer": style(~flex=8., ~paddingLeft=20.->dp, ()),
      "name":
        style(
          ~fontWeight=`bold,
          ~fontFamily=Typography.medium,
          ~fontSize=17.,
          ~marginBottom=5.->dp,
          ~color=Colors.primaryText,
          (),
        ),
      "avatarContainer":
        style(
          ~flex=2.,
          ~borderRadius=4.,
          ~overflow=`hidden,
          ~flexDirection=`row,
          ~justifyContent=`flexStart,
          (),
        ),
      "avatar": style(~width=60.->dp, ~height=70.->dp, ()),
      "speakerName":
        style(
          ~fontSize=14.,
          ~color=Colors.primaryText,
          ~fontFamily=Typography.primary,
          (),
        ),
    },
  );
