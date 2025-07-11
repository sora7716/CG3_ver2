#pragma once
#include "engine/math/RenderingData.h"

/// <summary>
/// レンダリング
/// </summary>
class Rendering {
public://メンバ関数
	/// <summary>
	/// 拡大縮小
	/// </summary>
	/// <param name="scale">倍率</param>
	/// <returns>倍率のmatrix</returns>
	static Matrix4x4 MakeScaleMatrix(const Vector3& scale);

	/// <summary>
	/// 平行移動
	/// </summary>
	/// <param name="translate">移動</param>
	/// <returns>移動のmatrix</returns>
	static Matrix4x4 MakeTranslateMatrix(const Vector3& translate);

	/// <summary>
	/// 同次座標系で計算し、デカルト座標系で返す
	/// </summary>
	/// <param name="vector">vector</param>
	/// <param name="matrix">matrix</param>
	/// <returns>デカルト座標系</returns>
	static Vector3 TransformVector(const Vector3& vector, const Matrix4x4& matrix);

	/// <summary>
	/// x座標を軸に回転
	/// </summary>
	/// <param name="radian">角度</param>
	/// <returns>x座標を軸の回転</returns>
	static Matrix4x4 MakeRotateXMatrix(const float& radian);

	/// <summary>
	/// y座標を軸に回転
	/// </summary>
	/// <param name="radian">角度</param>
	/// <returns>y座標を軸の回転</returns>
	static Matrix4x4 MakeRotateYMatrix(const float& radian);

	/// <summary>
	/// z座標を軸に回転
	/// </summary>
	/// <param name="radian">角度</param>
	/// <returns>z座標を軸の回転</returns>
	static Matrix4x4 MakeRotateZMatrix(const float& radian);

	/// <summary>
	/// x,y,z座標で回転
	/// </summary>
	/// <param name="radian">角度</param>
	/// <returns>回転</returns>
	static Matrix4x4 MakeRotateXYZMatrix(const Vector3& radian);

	/// <summary>
	/// OBB用の回転行列
	/// </summary>
	/// <param name="orientations">回転行列から抽出するやつ</param>
	/// <param name="rotate">回転する値</param>
	static void MakeOBBRotateMatrix(Vector3* orientations, const Vector3& rotate);


	/// <summary>
	/// OBB用のワールド行列
	/// </summary>
	/// <param name="orientations">回転行列から抽出したやつ</param>
	/// <param name="center">センターの値</param>
	/// <returns>OBBのワールド行列</returns>
	static Matrix4x4 MakeOBBWorldMatrix(const Vector3* orientations, const Vector3 center);

	/// <summary>
	/// アフィン行列の作成
	/// </summary>
	/// <param name="transform">トランスフォーム</param>
	/// <returns>アフィン行列</returns>
	static Matrix4x4 MakeAffineMatrix(const Transform& transform);

	/// <summary>
	/// STRの変換
	/// </summary>
	/// <param name="scale">倍率</param>
	/// <param name="rotate">回転</param>
	/// <param name="translate">移動</param>
	/// <returns>STRの変換</returns>
	static Matrix4x4 MakeSTRMatrix(const Vector3& scale, const Vector3& rotate, const Vector3& translate);

	/// <summary>
	/// UVのアフィン変換
	/// </summary>
	/// <param name="scale">倍率</param>
	/// <param name="rotate">回転</param>
	/// <param name="translate">移動</param>
	/// <returns></returns>
	static Matrix4x4 MakeUVAffineMatrix(const Vector3& scale, float rotate, const Vector3& translate);

	/// <summary>
	/// 正射影行列
	/// </summary>
	/// <param name="left">画面の左端</param>
	/// <param name="top">画面の上端</param>
	/// <param name="right">画面の右端</param>
	/// <param name="bottom">画面の下端</param>
	/// <param name="nearClip">近平面</param>
	/// <param name="farClip">遠平面</param>
	/// <returns>OrthographicMatrix</returns>
	static Matrix4x4 MakeOrthographicMatrix(const float& left, const float& top, const float& right, const float& bottom, const float& nearClip, const float& farClip);

	/// <summary>
	/// 透視投影行列
	/// </summary>
	/// <param name="fovY">画角</param>
	/// <param name="aspectRation">アスペクト比</param>
	/// <param name="nearClip">近平面への距離</param>
	/// <param name="farClip">遠平面への距離</param>
	/// <returns>PerspectiveFovMatrix</returns>
	static Matrix4x4 MakePerspectiveFovMatrix(const float& fovY, const float& aspectRation, const float& nearClip, const float& farClip);

	/// <summary>
	/// ビューポートmatrix
	/// </summary>
	/// <param name="left">左</param>
	/// <param name="top">上</param>
	/// <param name="width">横幅</param>
	/// <param name="height">縦幅</param>
	/// <param name="minDepth">最小深度値</param>
	/// <param name="maxDepth">最大深度値</param>
	/// <returns>ViewportMatrix</returns>
	static Matrix4x4 MakeViewportMatrix(const float& left, const float& top, const float& width, const float& height, const float& minDepth, const float& maxDepth);

	/// <summary>
	/// ビルボード行列の作成
	/// </summary>
	/// <param name="cameraWorldMatrix">カメラのワールド行列</param>
	/// <param name="rotate">回転</param>
	/// <returns>ビルボード行列</returns>
	static Matrix4x4 MakeBillboardMatrix(const Matrix4x4& cameraWorldMatrix, const Vector3& rotate);

	/// <summary>
	/// ビルボード行列を含んだアフィン行列の作成
	/// </summary>
	/// <param name="cameraWorldMatrix">カメラのワールド行列</param>
	/// <param name="transform">トランスフォーム</param>
	/// <returns>ビルボード行列を含んだアフィン行列</returns>
	static Matrix4x4 MakeBillboardAffineMatrix(const Matrix4x4& cameraWorldMatrix, const Transform& transform);
};
