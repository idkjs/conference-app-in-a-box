open ReactNative;

include Theme;

module Pager = {
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
};
module Talk = {
  include Theme;
  let styles =
    StyleSheet.create(
      Style.{
        "avatar":
          style(
            ~width=(dimensions##width -. 40.)->dp,
            ~height=300.->dp,
            ~borderRadius=15.,
            (),
          ),
        "container":
          style(
            ~flex=1.,
            ~padding=30.->dp,
            ~backgroundColor=Colors.primaryLight,
            (),
          ),
        "title":
          style(
            ~fontSize=22.,
            ~marginTop=15.->dp,
            ~color=Colors.primaryText,
            ~fontFamily=Typography.medium,
            (),
          ),
        "name":
          style(
            ~fontSize=26.,
            ~marginBottom=20.->dp,
            ~marginTop=20.->dp,
            ~color=Colors.highlight,
            ~fontFamily=Typography.medium,
            (),
          ),
        "speakerName":
          style(
            ~marginBottom=5.->dp,
            ~fontSize=16.,
            ~color=Colors.primaryText,
            ~fontFamily=Typography.medium,
            (),
          ),

        "time":
          style(~color=Colors.highlight, ~fontFamily=Typography.medium, ()),

        "summary":
          style(
            ~marginTop=4.->dp,
            ~color=Colors.primaryText,
            ~fontFamily=Typography.primary,
            (),
          ),

        "speakerBio": style(~color=Colors.primaryText, ()),
      },
    );
};
module Schedule = {
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
        "container":
          style(~flex=1., ~backgroundColor=Colors.primaryLight, ()),
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
          style(
            ~color=Colors.primaryText,
            ~fontFamily=Typography.primary,
            (),
          ),
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
};

module Discussion = {
  include Theme;
  let styles =
    StyleSheet.create(
      Style.{
        "buttonContainer": style(~flexDirection=`row, ()),
        "input":
          style(
            ~width=dimensions##width->dp,
            ~height=50.->dp,
            ~backgroundColor="#fff",
            ~paddingHorizontal=8.->dp,
            ~fontFamily=Typography.primary,
            ~fontSize=16.,
            (),
          ),
        "container": style(~flex=1., ~backgroundColor=Colors.primary, ()),
        "scrollViewContainer": style(~flex=1., ~paddingBottom=50.->dp, ()),
        "time": style(~color="rgba(0, 0, 0, .5)", ()),
        "message":
          style(
            ~fontFamily=Typography.primary,
            ~color=Colors.primaryText,
            ~fontSize=16.,
            (),
          ),
        "createdBy":
          style(
            ~fontFamily=Typography.primary,
            ~color=Colors.highlight,
            ~marginTop=4.->dp,
            (),
          ),
        "comment":
          style(
            ~paddingHorizontal=10.->dp,
            ~paddingVertical=15.->dp,
            ~borderRadius=5.,
            ~backgroundColor=Colors.primaryDark,
            ~borderBottomColor="#25223e",
            ~borderBottomWidth=1.,
            (),
          ),
      },
    );
};

module Profile = {
include Theme;
let styles =
  StyleSheet.create(
    Style.{
      "buttonContainer": style(~flexDirection=`row, ()),
      "button":
        style(
          ~width=110.->dp,
          ~borderWidth=1.,
          ~borderColor=Colors.highlight,
          ~height=35.->dp,
          ~justifyContent=`center,
          ~alignItems=`center,
          ~marginTop=15.->dp,
          ~marginLeft=(-1.)->dp,
          ~marginRight=15.->dp,
          (),
        ),
      "buttonText":
        style(
          ~color=Colors.primaryText,
          ~marginTop=3.->dp,
          ~fontFamily=Typography.primary,
          ~fontSize=13.,
          (),
        ),
      "input":
        style(
          ~height=45.->dp,
          ~width=(dimensions##width -. 30.)->dp,
          ~borderBottomWidth=2.,
          ~marginBottom=8.->dp,
          ~color="rgba(255, 255, 255, .5)",
          ~fontSize=18.,
          ~fontFamily=Typography.primary,
          ~borderBottomColor=Colors.highlight,
          (),
        ),
      "twitterHandle":
        style(
          ~color=Colors.primaryText,
          ~fontFamily=Typography.primary,
          ~fontSize=18.,
          ~marginLeft=15.->dp,
          (),
        ),
      "iconContainer":
        style(
          ~marginTop=5.->dp,
          ~flexDirection=`row,
          ~alignItems=`center,
          (),
        ),
      "gitHub": style(~marginTop=1.->dp, ()),
      "container": style(~flex=1., ~backgroundColor=Colors.primary2, ()),
      "profileContainer": style(~padding=20.->dp, ()),
      "username":
        style(
          ~fontSize=26.,
          ~marginBottom=3.->dp,
          ~color=Colors.primaryText,
          ~fontFamily=Typography.primary,
          (),
        ),
      "email":
        style(
          ~color=Colors.primaryText,
          ~fontSize=18.,
          ~marginBottom=10.->dp,
          ~fontFamily=Typography.primary,
          (),
        ),
    },
  );
}