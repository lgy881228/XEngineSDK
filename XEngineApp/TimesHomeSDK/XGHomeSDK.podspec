#
# Be sure to run `pod lib lint CLAAccount.podspec' to ensure this is a
# valid spec before submitting.
#
# Any lines starting with a # are optional, but their use is encouraged
# To learn more about a Podspec see http://guides.cocoapods.org/syntax/podspec.html
#

Pod::Spec.new do |s|
  s.name             = 'XGHomeSDK'
  s.version          = '1.0.0'
  s.summary          = 'A short description of XGHomeSDK.'

# This description is used to generate tags and improve search results.
#   * Think: What does it do? Why did you write it? What is the focus?
#   * Try to keep it short, snappy and to the point.
#   * Write the description between the DESC delimiters below.
#   * Finally, don't worry about the indent, CocoaPods strips it!

  s.description      = <<-DESC
  iOS library for xlink restful request
DESC

  s.homepage         = 'http://XGHomeSDK'
  # s.screenshots     = 'www.example.com/screenshots_1', 'www.example.com/screenshots_2'
  s.license          = { :type => 'Copyright', :text => 'xlink.inc copyright' }
  s.author           = { 'app-generate' => 'qinfengjiao@xlink.cn' }
  s.source           = { :git => 'http://XGHomeSDK', :tag => s.version.to_s }

  s.ios.deployment_target = '9.0'
  s.vendored_frameworks ='XGHomeSDK/*.framework'
  s.resources = 'XGHomeSDK/*.bundle'
  s.frameworks = 'Foundation'
  s.requires_arc = true
  s.dependency 'MJExtension'
  s.dependency 'AFNetworking'
    s.dependency 'CocoaLumberjack'
    s.dependency 'MBProgressHUD'
    s.dependency 'ReactiveObjC'
    s.dependency 'JKCategories'
    
    s.dependency 'DZNEmptyDataSet'
    s.dependency 'MJRefresh'
    
    s.dependency 'Masonry'
    s.dependency 'SDWebImage'
    
    s.dependency 'YYText'
    
    # alinyun
    s.dependency 'IMSLaunchKit'

    s.dependency 'Reachability', '3.2'
    s.dependency 'JKCategories'
    s.dependency 'IMSApiClient', '1.6.0'
    s.dependency 'IMSBoneKit', '1.3.5.2'
    s.dependency 'AKReactNative', '0.59.9.1'
    s.dependency 'ZipArchive', '1.4.0'
    s.dependency 'IMSMobileChannel', '1.6.6'
    s.dependency 'IMSDeviceGateway', '1.6.6'
    s.dependency 'IMSBreezeSDK', '1.6.8'
    s.dependency 'IMSOtaBusinessSdk', '1.6.3'
    s.dependency 'IMSReactNativeExtension', '1.0.0'
    s.dependency 'IMSAuthentication', '1.4.1'
    s.dependency 'AlicloudALBBOpenAccount', '3.4.0.35'
    s.dependency 'IMSThingCapability', '1.7.4'
    s.dependency 'IMSDeviceCenter', '1.10.5'
    s.dependency 'CocoaAsyncSocket', '7.4.2'
    s.dependency 'AlicloudPushIoT', '1.9.5.5'
    s.dependency 'IMSInitCode'
    s.dependency 'IMSGlueCode'
    s.dependency 'XLHContainerFramework'

end
